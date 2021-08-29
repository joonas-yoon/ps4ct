class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = 0, total = 0;
        vector<int> rs(n, 0), cs(n, 0);
        for(int r=0; r<n; ++r){
            for(int c=0; c<n; ++c) {
                rs[r] = max(rs[r], grid[r][c]);
                total += grid[r][c];
            }
        }
        for(int r=0; r<n; ++r){
            for(int c=0; c<n; ++c) cs[c] = max(cs[c], grid[r][c]);
        }
        for(int r=0; r<n; ++r){
            for(int c=0; c<n; ++c) {
                sum += min(rs[r], cs[c]);
            }
        }
        return sum - total;
    }
};