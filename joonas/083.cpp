#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

struct bus {
    int s, e, i;
    bool isCover(const bus& o) {
        return s <= o.s && o.e <= e;
    }
    bool operator < (const bus& o) const {
        if (e == o.e) return s > o.s;
        return e < o.e;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<bus> v;
    vector<bool> live(m, true);
    for (int id = 0; id < m; ++id) {
        int s, e;
        scanf("%d %d", &s, &e);
        if (s > e) {
            v.push_back({ s, n + e, id });
        }
        else {
            v.push_back({ s, e, id });
            v.push_back({ n + s, n + e, id });
        }
    }
    sort(all(v));

    stack<bus> s;
    for (auto& b : v) {
        while (!s.empty() && b.isCover(s.top())) {
            live[s.top().i] = false;
            s.pop();
        }
        s.push(b);
    }

    for (int id = 0; id < m; ++id) {
        if (live[id]) printf("%d ", id + 1);
    }

    return 0;
}