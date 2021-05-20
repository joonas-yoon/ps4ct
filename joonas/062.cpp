#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

int h, w;
int color[1000][1000];
char s[1000][1001];
int dist[1000001];

int dfs(int y, int x, int c) {
    if (color[y][x] != -1) return 0;
    int cnt = 1;
    color[y][x] = c;
    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d], nx = x + dx[d];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
        if (s[ny][nx] == '0') cnt += dfs(ny, nx, c);
    }
    return cnt;
}

int main() {
    memset(color, -1, sizeof(color));

    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++i) scanf("%s", s[i]);
    for (int i = 0, c = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '0') {
                dist[c] = dfs(i, j, c);
                c++;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '1') {
                set<int> colors;
                for (int d = 0; d < 4; ++d) {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                    colors.insert(color[ny][nx]);
                }
                int ans = 1; // itself
                for (auto& c : colors) ans += dist[c];
                printf("%d", ans % 10);
            }
            else putchar('0');
        }
        puts("");
    }

    return 0;
}
