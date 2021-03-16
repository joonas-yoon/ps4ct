#include <string>
#include <vector>

using namespace std;

bool isOut(int x, int a) {
    return !(0 <= x && x < a);
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int kn = key.size();
    int ln = lock.size();

    int hole = 0;
    for (auto& row : lock) for (auto& col : row) hole += !col;

    // 4방향으로 회전
    for (int rot = 0; rot < 4; ++rot) {
        // x, y축 모두 슬라이딩
        for (int y0 = -(kn - 1); y0 < ln; ++y0) {
            for (int x0 = -(kn - 1); x0 < ln; ++x0) {
                vector<vector<int>> L(lock);
                for (int y = 0; y < kn; ++y) {
                    int yl = y0 + y;
                    if (isOut(yl, ln)) continue;
                    for (int x = 0; x < kn; ++x) {
                        int xl = x0 + x;
                        if (isOut(xl, ln)) continue;
                        // 자물쇠/열쇠가 맞물린 경우
                        L[yl][xl] ^= key[y][x];
                    }
                }

                bool success = true;
                for (auto& r : L) for (auto& l : r) success &= l;
                if (success) return true;
            }
        }

        // rotate key
        vector<vector<int>> k(kn, vector<int>(kn));
        for (int i = 0; i < kn; ++i) {
            for (int j = 0; j < kn; ++j) {
                k[i][j] = key[j][kn - 1 - i];
            }
        }
        key = k;
    }

    return false;
}