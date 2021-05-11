class Solution {
public:
    bool attachable(char a, char b) {
        if (a == '1') return true;
        if (a == '2') return b <= '6';
        return false;
    }
    int ans[1001];
    int solve(const string& s, int i) {
        if (i >= s.length()) return 1;
        int& ret = ans[i];
        if (ret != -1) return ret;
        ret = 0;
        if (i + 1 < s.length() && attachable(s[i], s[i+1]))
            ret += solve(s, i + 2);
        if (s[i] != '0')
            ret += solve(s, i + 1);
        return ret;
    }
    int numDecodings(string s) {
        memset(ans, -1, sizeof(ans));
        if (s == "0") return 0;
        return solve(s, 0);
    }
};