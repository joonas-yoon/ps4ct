#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int w[10001];
bool vis[10001];
int dp[10001][2];

int great(int cur, bool chosen){
    int& ans = dp[cur][chosen];
    if (ans != -1) return ans;
    vis[cur] = true;
    ans = chosen ? w[cur] : 0;
    for (auto& next : adj[cur]) {
        if (vis[next]) continue;
        int ret = great(next, false);
        if (!chosen) ret = max(ret, great(next, true));
        ans += ret;
    }
    vis[cur] = false;
    return ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &w[i]);
    for(int i=1; i<n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    printf("%d\n", max(great(0, true), great(0, false)));

    return 0;
}