#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long lld;
typedef pair<int, int> ii;

struct point {
    int x, y, z, id;
};

struct tunnel {
    int a, b, c;
    bool operator < (const tunnel& t) const {
        return c < t.c;
    }
};

int cost(point& a, point& b) {
    return min({ abs(a.x - b.x), abs(a.y - b.y), abs(a.z - b.z) });
}

int g[100001];
int _find(int p) {
    if (p == g[p]) return p;
    return g[p] = _find(g[p]);
}
bool _union(int p, int q) {
    p = _find(p);
    q = _find(q);
    g[q] = p;
    return p != q;
}

int main() {
    int n, id = 0;
    scanf("%d", &n);
    vector<point> p(n);
    for (auto& i : p) {
        scanf("%d %d %d", &i.x, &i.y, &i.z);
        i.id = id++;
    }

    vector<tunnel> e;

    sort(all(p), [](auto& i, auto& j) { return i.x < j.x; });
    for (int i = 1; i < n; ++i) e.push_back({ p[i - 1].id, p[i].id, cost(p[i - 1], p[i]) });

    sort(all(p), [](auto& i, auto& j) { return i.y < j.y; });
    for (int i = 1; i < n; ++i) e.push_back({ p[i - 1].id, p[i].id, cost(p[i - 1], p[i]) });

    sort(all(p), [](auto& i, auto& j) { return i.z < j.z; });
    for (int i = 1; i < n; ++i) e.push_back({ p[i - 1].id, p[i].id, cost(p[i - 1], p[i]) });

    sort(all(e));
    for (int i = 0; i < n; ++i) g[i] = i;

    lld answer = 0;
    for (auto& i : e) {
        if (_union(i.a, i.b)) answer += i.c;
    }
    printf("%lld\n", answer);

    return 0;
}