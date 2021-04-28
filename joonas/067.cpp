#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;

void solve() {
    int n, m, w;
    scanf("%d %d %d", &n, &m, &w);
    vector<vector<ii>> adj(500, vector<ii>());
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        adj[a - 1].push_back(ii(b - 1, t));
        adj[b - 1].push_back(ii(a - 1, t));
    }
    for (int i = 0; i < w; ++i) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        adj[a - 1].push_back(ii(b - 1, -t));
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    bool cycle = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for(auto& next : adj[j]){
                int k = next.first;
                if (dist[k] > dist[j] + next.second) {
                    dist[k] = dist[j] + next.second;
                    cycle |= i == n - 1;
                }
            }
        }
    }
    puts(cycle ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}