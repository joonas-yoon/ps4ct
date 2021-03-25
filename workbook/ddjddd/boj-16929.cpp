#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

char table[51][51];
bool visit[51][51];
int maxX, maxY;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool inbound(int nx, int ny) {
    if (nx >= 0 && nx < maxX && ny >= 0 && ny < maxY) return true;
    return false;
}

bool ans;
int sx, sy;
void dfs_2(int x, int y, int depth) {
    if (ans) return;
    visit[x][y] = true;
    int value = table[x][y];

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (inbound(nx, ny) && value == table[nx][ny]) {
            if (visit[nx][ny]) {
                if (depth >= 3 && nx == sx && ny == sy) {
                    ans = true;
                    return;
                }
            }
            else {
                visit[nx][ny] = true;
                dfs_2(nx, ny, depth + 1);
                visit[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> maxX >> maxY;
    for (int i = 0; i < maxX; i++) cin >> table[i];
    memset(visit, 0, sizeof(bool) * 21 * 21);

    bool ret = false;
    for (int i = 0; i < maxX && !ans; i++) {
        for (int j = 0; j < maxY && !ans; j++) {
            sx = i, sy = j;
            visit[i][j] = true;
            dfs_2(i, j, 0);
        }
    }

    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}