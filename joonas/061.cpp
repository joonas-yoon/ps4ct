#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,-1,0,1 };

char g[1000][1001];
bool v[1000][1001][2];

struct cell {
    int x, y, b;
};

int solve() {
    int H, W;
    scanf("%d %d ", &H, &W);
    for (int i = 0; i < H; ++i) scanf("%s", g[i]);
    queue<cell> q;
    q.push({ 0, 0, false });
    v[0][0][0] = 0;
    int dist = 1;
    while (!q.empty()) {
        int qs = q.size();
        while (qs--) {
            int x = q.front().x;
            int y = q.front().y;
            int b = q.front().b;
            q.pop();

            if (x == W - 1 && y == H - 1)
                return dist;

            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                bool br = (g[ny][nx] == '1');
                if (v[ny][nx][b] || (b & br)) continue;
                v[ny][nx][b] = true;
                q.push({ nx, ny, b | br });
            }
        }
        ++dist;
    }
    return -1;
}

int main() {
    printf("%d\n", solve());
    return 0;
}