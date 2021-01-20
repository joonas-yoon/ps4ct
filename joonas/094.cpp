#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f3f;
vector<ii> adj[10001];

// return (node, dist)
ii farthest(int from, int n) {
    queue<ii> q;
    vector<int> d(n, INF);
    q.push({ from, 0 }); // (node, dist)
    d[from] = 0;
    while (!q.empty()) {
        int c = q.front().first;
        int w = q.front().second;
        q.pop();

        for (auto& next : adj[c]) {
            if (d[next.first] != INF) continue;
            d[next.first] = w + next.second;
            q.push({ next.first, d[next.first] });
        }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (d[ans] < d[i]) ans = i;
    }
    return make_pair(ans, d[ans]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int s, e, w, i = 1; i < n; ++i) {
        scanf("%d %d %d", &s, &e, &w);
        adj[s - 1].push_back({ e - 1, w });
        adj[e - 1].push_back({ s - 1, w });
    }

    auto one = farthest(0, n);
    auto two = farthest(one.first, n);
    printf("%d\n", two.second);

    return 0;
}