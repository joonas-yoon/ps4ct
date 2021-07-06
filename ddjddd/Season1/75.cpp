class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for (int x = 0; x < len / 2; x++) {
            for (int y = x; y < len - x - 1; y++) {
                int temp = matrix[x][y];
                matrix[x][y] = matrix[len - 1 - y][x];
                matrix[len - 1 - y][x] = matrix[len - 1 - x][len - 1 - y];
                matrix[len - 1 - x][len - 1 - y] = matrix[y][len - 1 - x];
                matrix[y][len - 1 - x] = temp;
            }
        }
    }
};