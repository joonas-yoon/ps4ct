#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<string> dict;
    string inputStr;

    bool wordBreak(string s, vector<string>& wordDict) {
        dict = wordDict;
        inputStr = s;
        vector<bool> memo(s.size() + 1, true);
        return dfs(0, memo);
    }

    bool dfs(int sidx, vector<bool>& memo) {
        if (sidx == inputStr.size()) {
            return true;
        }

        for (const auto& word : dict) {
            int nidx = sidx + word.size();
            if (nidx > inputStr.size()) {
                continue;
            }

            if (memo[nidx] && inputStr.substr(sidx, word.size()) == word) {
                if (dfs(nidx, memo)) {
                    return true;
                }
            }
        }

        memo[sidx] = false;
        return false;
    }
};