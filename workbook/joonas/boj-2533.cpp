#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001

vector<int> adj[MAX_N];

int dp[MAX_N][2];
bool vis[MAX_N];

int f(int node, bool choose) {
    int& ans = dp[node][choose];
    if (ans != -1) return ans;
    vis[node] = true;
    ans = choose;
    for (auto& next : adj[node]) {
        if (vis[next]) continue;
        int g = f(next, true);
        if (choose) g = min(g, f(next, false));
        ans += g;
    }
    vis[node] = false;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", min(f(1, true), f(1, false)));

    return 0;
}