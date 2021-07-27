#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long lld;

int main() {
    int T, an, bn;
    int a[1001], b[1001];
    scanf("%d %d", &T, &an);
    for (int i = 0; i < an; ++i) scanf("%d", &a[i]);
    scanf("%d", &bn);
    for (int i = 0; i < bn; ++i) scanf("%d", &b[i]);

    vector<int> aa, bb;
    for (int i = 0; i < an; ++i) {
        int s = 0;
        for (int j = i; j < an; ++j) {
            s += a[j];
            aa.push_back(s);
        }
    }
    for (int i = 0; i < bn; ++i) {
        int s = 0;
        for (int j = i; j < bn; ++j) {
            s += b[j];
            bb.push_back(s);
        }
    }
    sort(all(aa));
    sort(all(bb));

    lld answer = 0;
    for (auto& x : aa) {
        auto r = equal_range(all(bb), T - x);
        answer += r.second - r.first;
    }
    printf("%lld\n", answer);

    return 0;
}