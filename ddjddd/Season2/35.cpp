class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();

        vector<int> hor(n, 0), ver(n, 0);

        for(int i = 0; i < n; i++) {
            int m = 0;
            for(int j = 0; j < n; j++) {
                m = max(m, grid[i][j]);
                ver[j] = max(ver[j], grid[i][j]);
            }
            hor[i] = m;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += min(hor[i], ver[j]) - grid[i][j];
            }
        }

        return ans;
    }
};