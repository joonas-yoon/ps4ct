#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> adj[100];
int t[100];
bool vis[100], res[100];

void dfs(int cur, int d) {
    if (d < 0 || vis[cur]) return;
    vis[cur] = res[cur] = true;
    for (auto& next : adj[cur]) {
        dfs(next.first, d - next.second);
    }
    vis[cur] = false;
}

int main() {
    int v, m, e;
    scanf("%d %d %d", &v, &m, &e);
    for (int i = 0; i < v; ++i) scanf("%d", &t[i]);
    while (e--) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        adj[x - 1].push_back(ii(y - 1, d));
        adj[y - 1].push_back(ii(x - 1, d));
    }

    int ans = 0;
    for (int i = 0; i < v; ++i) {
        memset(res, 0, sizeof(res));
        dfs(i, m);
        int sum = 0;
        for (int j = 0; j < v; ++j) {
            if (res[j]) sum += t[j];
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);

    return 0;
}