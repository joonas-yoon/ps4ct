#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long lld;
typedef pair<int, int> ii;

const int dy[]={-1,0,1,0};
const int dx[]={0,-1,0,1};

int H, W = 10;
bool vis[101][11];
char a[101][11];

vector<ii> regions(int y, int x) {
    vector<ii> pt;
    queue<ii> q;
    char color = a[y][x];
    q.push(make_pair(y, x));
    vis[y][x] = true;
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        pt.push_back(q.front());
        q.pop();
        
        for(int d = 0; d < 4; ++d) {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (vis[ny][nx] || a[ny][nx] != color) continue;
            q.push(make_pair(ny, nx));
            vis[ny][nx] = true;
        }
    }
    return pt;
}

void gravity(int xs[]) {
    for (int x = 0; x < W; ++x) {
        if (!xs[x]) continue;
        int r = H - 1;
        for (int i = H - 1; i >= 0; --i) {
            if (a[i][x] != '0') a[r--][x] = a[i][x];
        }
        for (; r >= 0; --r) a[r][x] = '0';
    }
}

int main() {
    int k;
    scanf("%d %d ", &H, &k);
    for(int i = 0; i < H; ++i) scanf("%s ", a[i]);

    bool changed;
    do {
        memset(vis, false, sizeof(vis));
        changed = false;
        int xs[11] = {};
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                if (!vis[i][j] && a[i][j] !='0') {
                    auto v = regions(i, j);
                    if (v.size() >= k) {
                        for(auto& p : v) {
                            a[p.first][p.second] = '0';
                            xs[p.second] = true;
                        }
                        changed = true;
                    }
                }
            }
        }
        if (changed) gravity(xs);
    } while (changed);

    for(int i = 0; i < H; ++i) puts(a[i]);
    puts("");

    return 0;
}