#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<stack<int>> s(board.size());
    for (int r = board.size()-1; r >= 0; --r) {
        for (int c = 0; c < board[r].size(); ++c) {
            if (board[r][c] > 0) s[c].push(board[r][c]);
        }
    }
    stack<int> z;
    int answer = 0;
    for (auto& m : moves) {
        if (s[m-1].empty()) continue;
        if (!z.empty() && s[m-1].top() == z.top()) {
            z.pop();
            answer += 2;
        } else {
            z.push(s[m-1].top());
        }
        s[m-1].pop();
    }
    return answer;
}