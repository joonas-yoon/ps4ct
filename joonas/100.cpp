#include <string>
#include <vector>
#include <cstring>

using namespace std;

int a[1001][1001];
int dy[] = { 1, 0, -1 };
int dx[] = { 0, 1, -1 };

vector<int> solution(int n) {
    memset(a, -1, sizeof(a));

    int r = 0, c = 0, l = n - 1, x = 0;
    a[0][0] = ++x;
    while (l > 0) {
        for (int i = 0; i < 3 && l > 0; ++i, --l) {
            for (int j = 0; j < l; ++j) {
                r += dy[i];
                c += dx[i];
                a[r][c] = ++x;
            }
            l += c == 0;
        }
    }
    
    vector<int> answer;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; a[i][j] != -1; ++j) answer.push_back(a[i][j]);
    }
    return answer;
}
