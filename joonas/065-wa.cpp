#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

static int dy[] = {-1,0,1,0};
static int dx[] = {0,1,0,-1};

int n, h;
int id[300][300];

// coloring
void dfs(vector<vector<int>>& a, int y, int x, int color){
    id[y][x] = color;
    for (int d=0; d<4; ++d){
        int ny = y + dy[d], nx = x + dx[d];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (id[ny][nx] != -1 || abs(a[y][x] - a[ny][nx]) > h) continue;
        dfs(a, ny, nx, color);
    }
}

// disjoint set
int grp[90001];
int _find(int p) {
    if (grp[p] == p) return p;
    return grp[p] = _find(grp[p]);
}
bool _merge(int u, int v){
    u = _find(u);
    v = _find(v);
    grp[v] = u;
    return u != v;
}

struct edge {
    int a, b, w;
    bool operator < (const edge& e) const {
        return w > e.w;
    }
};

int solution(vector<vector<int>> land, int height) {
    n = land.size();
    h = height;
    int newid = 0;
    memset(id, -1, sizeof(id));
    vector<pair<int, int>> xys;
    for (int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if (id[i][j] == -1) {
                dfs(land, i, j, newid++);
                xys.push_back({i, j});
            }
        }
    }
    
    priority_queue<edge> pq;
    for (auto& xy : xys) {
        queue<pair<int, int>> q;
        bool vis[300][300] = {};
        q.push(xy);
        int color = id[xy.first][xy.second];
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            vis[y][x] = true;
            
            for (int d=0; d<4; ++d) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || vis[ny][nx]) continue;
                if (id[ny][nx] == color) q.push({ny, nx});
                else pq.push({color, id[ny][nx], abs(land[y][x] - land[ny][nx])});
            }
        }
    }
    
    // init disjoint set
    for (int i=0; i<newid; ++i) grp[i] = i;
    
    int answer = 0;
    while (!pq.empty()){
        const edge& e = pq.top();
        if (_merge(e.a, e.b)) {
            answer += e.w;
        }
        pq.pop();
    }
    return answer;
}