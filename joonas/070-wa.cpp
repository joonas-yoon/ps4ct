typedef long long lld;

class Solution {
public:
    // [l, r)
    lld solve(vector<int>& a, int l, int r) {
        lld ans = a[l];
        int n = r - l;
        // sliding window
        for (int w = 1; w <= min(n, 32); ++w) {
            lld p = 1;
            int i = l;
            for (; i < l + w; ++i) p *= a[i];
            ans = max(ans, p);
            for (; i < r; ++i) {
                p /= a[i - w];
                p *= a[i];
                ans = max(ans, p);
            }
        }
        return ans;
    }

    // WA: [2, 1, 1, 1, ..., 1, 10, 10, 10, 10, 10, 10, 10, 10, 10] = 2*10^9, but 10^9
    int maxProduct(vector<int>& a) {
        int l = 0, n = a.size();
        lld ans = a[0];
        for (int r = 0; r < n; ++r) {
            if (a[r] == 0) {
                ans = max(ans, 0LL);
                ans = max(ans, solve(a, l, r));
                l = r + 1;
            }
        }
        if (l < n) ans = max(ans, solve(a, l, n));
        return ans;
    }
};