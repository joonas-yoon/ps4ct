#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> tBrd[31], s;

void transpose(vector<vector<int>> board) {
    int x = board.size(), y = board[0].size();
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            int tmp = board[x-1-i][j];
            if(tmp) tBrd[j+1].push(tmp);
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    transpose(board);

    for(auto& it: moves) {
        if(tBrd[it].size()) {
            if(s.size() && s.top() == tBrd[it].top()) {
                s.pop();
                answer += 2;
            }
            else {
                s.push(tBrd[it].top());
            }
            tBrd[it].pop();
        }
    }

    return answer;
}