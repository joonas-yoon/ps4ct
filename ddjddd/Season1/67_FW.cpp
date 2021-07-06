#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 501, INF = 987654321;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tC; cin >> tC;
    for (int tc = 1; tc <= tC; tc++) {
        int n, m, w;
        int a, b, c;
        int table[MAX][MAX];

        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                table[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            if (c < table[a][b]) table[a][b] = table[b][a] = c;
        }
        for (int i = 0; i < w; i++) {
            cin >> a >> b >> c;
            if (-c < table[a][b]) table[a][b] = -c;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (table[i][k] + table[k][j] < table[i][j]) {
                        table[i][j] = table[i][k] + table[k][j];
                    }
                }
            }
        }

        bool isCycle = false;
        for (int i = 1; i <= n; i++) if (table[i][i] < 0) isCycle = true;

        if (isCycle) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
