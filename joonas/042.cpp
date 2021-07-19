class Solution {
public:
    int h, w;
    vector<vector<char>> s;
    char v[6][6][15][5];
    bool vis[6][6];
    string word;

    char solve(int y, int x, int wi, int pd) {
        if (y < 0 || y >= h || x < 0 || x >= w || word[wi] != s[y][x] || vis[y][x]) return 0;
        if (wi + 1 >= word.length()) return 1;
        vis[y][x] = true;
        char& ret = v[y][x][wi][pd];
        if (ret == 1) {
            vis[y][x] = false;
            return ret;
        }
        ret = 0;
        const int dy[] = { 1,0,-1,0 };
        const int dx[] = { 0,-1,0,1 };
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if (solve(ny, nx, wi + 1, i) == 1) {
                ret = 1;
                break;
            }
        }
        vis[y][x] = false;
        return ret;
    }

    bool exist(vector<vector<char>>& board, string _w) {
        memset(v, -1, sizeof(v));
        s = board;
        h = board.size();
        w = board[0].size();
        word = _w;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (solve(i, j, 0, 4) == 1) return true;
            }
        }
        return false;
    }
};