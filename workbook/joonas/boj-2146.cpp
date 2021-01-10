#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,-1,0,1 };

int n, a[101][101];
int D[101][101];
bool v[101][101];

void dfs(int y, int x, int c) {
    if (y < 0 || y >= n || x < 0 || x >= n || a[y][x] == 0 || v[y][x]) return;
    a[y][x] = c;
    v[y][x] = true;
    for (int i=0; i<4; ++i){
        dfs(y + dy[i], x + dx[i], c);
    }
}

int main() {
    scanf("%d", &n);
    queue<ii> q;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", &a[i][j]);
            if (a[i][j]) {
                q.push(make_pair(i, j));
                D[i][j] = 0;
            } else {
                D[i][j] = INF;
            }
        }
    }
    for(int i=0, colors=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if (a[i][j] && !v[i][j]) dfs(i, j, ++colors);
        }
    }

    int ans = INF;
    while(!q.empty()){
        int qs = q.size();
        while(qs--){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int d=0; d<4; ++d){
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (a[ny][nx] == 0) {
                    D[ny][nx] = D[y][x] + 1;
                    a[ny][nx] = a[y][x];
                    q.push(make_pair(ny, nx));
                }
                else if (a[ny][nx] != a[y][x] && D[ny][nx] <= D[y][x]) {
                    ans = min(ans, D[y][x] + D[ny][nx]);
                }
           }
        }
    }
    printf("%d\n", ans < INF ? ans : 0);

    return 0;
}