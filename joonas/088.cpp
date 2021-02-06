#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long lld;
typedef pair<int, int> ii;

int n;
vector<pair<lld, ii>> edge;

lld dist(const ii& p1, const ii& p2) {
    return (lld)(p1.first - p2.first) * (p1.first - p2.first)
        + (lld)(p1.second - p2.second) * (p1.second - p2.second);
}

int gr[1003000];

int _find(int g) {
    if (g == gr[g]) return g;
    return gr[g] = _find(gr[g]);
}

// merge u -> v
// return: false when is already in same group
bool _merge(int u, int v) {
    u = _find(u);
    v = _find(v);
    if (u == v) return false;
    gr[u] = v;
    return true;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    vector<ii> p(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = make_pair(x - 1, y - 1);
    }

    for (int i = 0; i < n; ++i) gr[i] = i;

    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        _merge(x - 1, y - 1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            lld d = 0;
            if (_find(i) != _find(j)) {
                d = dist(p[i], p[j]);
            }
            edge.push_back(make_pair(d, make_pair(i, j)));
        }
    }

    sort(all(edge));

    double ans = 0;
    for (auto& e : edge) {
        int u = e.second.first;
        int v = e.second.second;
        lld d = e.first;

        if (!_merge(u, v)) continue;
        ans += sqrt(d);
    }
    printf("%.2lf\n", ans);

    return 0;
}