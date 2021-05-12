class Solution {
public:
    string tmp;
   int dp[100] = { 0, };

    bool valid(int a) {
        return tmp.at(a) != '0';
    }

    bool valid(int a, int b) {
        return (tmp.at(a) == '1') || (tmp.at(a) == '2' && tmp.at(b) <= '6');
    }

    int solve(int idx) {
        int digit = tmp.size() - idx;
        int ret = 0;

        if (digit <= 0) ret = 0;
        if (digit == 1 && valid(idx)) ret++;
        else if (digit == 2) {
            if (valid(idx, idx + 1)) ret++;
            if (valid(idx) && valid(idx + 1)) ret++;
        }
        else ret = (valid(idx) ? dp[idx + 1] : 0) + (valid(idx, idx + 1) ? dp[idx + 2] : 0);

        return ret;
    }

    int numDecodings(string s) {
        tmp = s;
        // dp.resize(s.size(), 0);
        for (int i = s.size(); i--; i >= 0) {
            dp[i] = solve(i);
        }

        int ans = dp[0];
        return ans;
    }
};
