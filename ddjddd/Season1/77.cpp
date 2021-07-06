#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
typedef vector<vector<int>> node;

int ls, ks, bs;

node rotate(node key) {
    node result(ks, vector<int>(ks, 0));

    for (int l = 0, ti = 0; l < ks; l++, ti++) {
        for (int i = ks - 1, tj = 0; i >= 0; i--, tj++) {
            result[ti][tj] = key[i][l];
        }
    }
    return result;
}

bool solution(node key, node lock) {
    ls = lock.size(), ks = key.size();
    bs = ls + (ks - 1) * 2;

    node board(bs, vector<int>(bs, 0));
    node tmp(bs, vector<int>(bs, 0));

    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < ls; j++) {
            board[i + (ks - 1)][j + (ks - 1)] = lock[i][j];
        }
    }

    bool ans = false;
    for (int m = 0; m < ls + ks - 1; m++) {
        for (int n = 0; n < ls + ks - 1; n++) {

            node tk = key;

            for (int r = 0; r < 4; r++) {
                tmp.clear();
                tmp.assign(board.begin(), board.end());
                for (int i = m, ti = 0; ti < ks; i++, ti++) {
                    for (int j = n, tj = 0; tj < ks; j++, tj++) {

                        tmp[i][j] = tmp[i][j] ^ tk[ti][tj];
                    }
                }

                tk = rotate(tk);
                ans = true;
                for (int i = 0; i < ls; i++) {
                    for (int j = 0; j < ls; j++) {
                        if (!tmp[i + (ks - 1)][j + (ks - 1)]) ans = false;
                    }
                }
                if (ans) return ans;
            }
        }
    }

    return false;
}