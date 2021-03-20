class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for(int j=0; 2 * j < n; ++j) {
            for(int i=0; i < n - 2 * j - 1; ++i) {
                int t = m[j][i+j];
                m[j][i+j] = m[n-1-i-j][j];
                m[n-1-i-j][j] = m[n-1-j][n-1-i-j];
                m[n-1-j][n-1-i-j] = m[i+j][n-1-j];
                m[i+j][n-1-j] = t;
            }
        }
    }
};