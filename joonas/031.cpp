#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long lld;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const lld LNF = 0x3f3f3f3f3f3f3f3f;

vector<pair<int, lld>> adj[1001];

lld dijkstra(int n, int s, int e) {
    vector<lld> d(n + 1, LNF);
    priority_queue<pair<lld, int>> pq;
    pq.push({ 0LL, s });
    d[s] = 0;
    while (!pq.empty()) {
        lld cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur == e) return cost;

        for (auto& next : adj[cur]) {
            int ni = next.first;
            lld nd = cost + next.second;
            if (d[ni] <= nd) continue;
            d[ni] = nd;
            pq.push({ -nd, ni });
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        adj[s].push_back({ e, w + 0LL });
    }
    for (int i = 1; i <= n; ++i) {
        sort(all(adj[i]), [](auto& x, auto& y) {
            if (x.second == y.second) return x.first < y.first;
            return x.second < y.second;
        });
    }

    int s, e;
    scanf("%d %d", &s, &e);
    printf("%lld\n", dijkstra(n, s, e));

    return 0;
}