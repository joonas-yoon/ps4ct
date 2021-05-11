class Solution {
public:
    vector<string> pats[301]; // patterns which starts here
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.length();
        for (int i = 0; i < sl; ++i) {
            for (auto& p : wordDict) {
                int pl = p.length();
                if (i + pl > sl) continue;
                if (strncmp(s.c_str() + i, p.c_str(), pl) == 0) {
                    pats[i].push_back(p);
                }
            }
        }
        
        // bfs
        queue<int> q; // pos
        vector<bool> visit(sl, false);
        visit[0] = true;
        for (auto p : pats[0]) q.push(p.length());
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            if (pos == s.length()) return true;
            if (visit[pos]) continue;
            visit[pos] = true;
            for (auto& next : pats[pos]) {
                q.push(pos + next.length());
            }
        }
        return false;
    }
};