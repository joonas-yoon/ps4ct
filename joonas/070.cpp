typedef long long lld;

class Solution {
public:
    int maxProduct(vector<int>& a) {
        int maxp = a[0], minp = a[0];
        int pmax = maxp, pmin = minp;
        int ans = a[0];
        for (int i = 1; i < a.size(); ++i) {
            maxp = max(a[i], max(pmax * a[i], pmin * a[i]));
            minp = min(a[i], min(pmax * a[i], pmin * a[i]));
            ans = max(ans, maxp);
            pmax = maxp;
            pmin = minp;
        }
        return ans;
    }
};