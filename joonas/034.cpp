typedef pair<int, int> ii;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        
        queue<ii> q;
        q.push({0, 0});
        bool v[101][101] = {};
        v[0][0] = true;
        
        while(!q.empty()){
            ii cur = q.front();
            q.pop();
            
            int i = cur.first, j = cur.second;
            int k = i + j;
            if (k == s3.length()) return true;
            
            if (s1[i] == s3[k] && !v[i+1][j]) {
                q.push({i+1, j});
                v[i+1][j] = true;
            }
            if (s2[j] == s3[k] && !v[i][j+1]) {
                q.push({i, j+1});
                v[i][j+1] = true;
            }
        }
        return false;
    }
};