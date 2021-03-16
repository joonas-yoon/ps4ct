#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    unsigned int d[201][201];
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; ++i) d[i][i] = 0;

    for (auto& e : fares) {
        d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (d[i][k] == INF) continue;
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    unsigned int ans = INF;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, d[s][i] + d[i][a] + d[i][b]);
    }
    return ans;
}