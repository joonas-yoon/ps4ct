#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tmin, tmax, ret;
        tmin = tmax = 1;
        ret = nums[0];

        for (auto& it : nums) {
            int ttmp = tmax;
            tmax = max(max(tmax * it, tmin * it), it);
            tmin = min(min(ttmp * it, tmin * it), it);
            ret = max(ret, tmax);
            // cout << tmax << ' ' << tmin << endl;
        }
        return ret;
    }
};