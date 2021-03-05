#include <bits/stdc++.h>
using namespace std;

struct range {
    int x, h, id;
    bool operator < (const range& o) const {
        if (h == o.h) return x < o.x;
        return h > o.h;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<range> bar;
    vector<int> starts(n + 1);
    set<range> pq;
    for (int id = 1; id <= n; ++id) {
        int s, e, h;
        scanf("%d %d %d", &s, &h, &e);
        starts[id] = s;
        bar.push_back({ s, h, id });  // [ open
        bar.push_back({ e, h, -id }); // ] close
    }

    // sort by x position
    sort(bar.begin(), bar.end(), [](auto& a, auto& b) {
        if (a.x == b.x) return a.id > b.id;
        return a.x < b.x;
    });

    int lastHeight = 0;
    for (auto& b : bar) {
        if (b.id > 0) // open
            pq.insert(b);
        else // close
            pq.erase(pq.find({starts[-b.id], b.h, -b.id }));

        int h = pq.empty() ? 0 : pq.begin()->h;
        if (lastHeight != h) {
            printf("%d %d ", b.x, h);
            lastHeight = h;
        }
    }

    return 0;
}