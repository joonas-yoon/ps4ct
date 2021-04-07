#include <bits/stdc++.h>
using namespace std;

// a[l, r)
vector<int> allCombs(int a[], int l, int r, int w) {
    int len = r - l;
    if (len < 1) return vector<int>();
    vector<int> v;
    for (int b = (1 << len) - 1; b; --b) {
        int sum = 0;
        bool poss = true;
        for (int i = 0, j = b; i < len && j; ++i, j >>= 1) {
            if ((1 << i) & b) sum += a[l + i];
            if (sum > w) {
                poss = false;
                break;
            }
        }
        if (poss) v.push_back(sum);
    }
    return v;
}

int main() {
    int n, c, a[30];
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    auto L = allCombs(a, 0, n / 2, c);
    auto R = allCombs(a, n / 2, n, c);

    int ans = L.size() + R.size() + 1; // single set + empty set
    for (auto& l : L) {
        for (auto& r : R) ans += (l + r <= c);
    }
    printf("%d\n", ans);

    return 0;
}