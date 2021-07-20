class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    string target;
    bool ans = false;

    void dfs(vector<vector<char>> &board, int x, int y, int depth){
        if(target.size() == 1) ans = true;
        if(ans) return;
        if(depth == target.size()) {
            ans = true;
            for(auto& it: board) {
                for(auto& iit: it) {
                    printf("%c", iit);
                }
                printf("\n");
            }
            return ;
        }
        if(board[x][y] != target[depth]) return;

        for(int d = 0; d < 4; d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                char c = board[x][y];
                board[x][y] = ' ';
                dfs(board, nx, ny, depth+1);
                board[x][y] = c;
            }
        }

        return;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        target = word;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]) dfs(board, i, j, 0);
            }
        }
        return ans;
    }
};