#include <iostream>
#include <cstring>

using namespace std;

int n, m, r;
const int MAX = 102;
int item[MAX];
int table[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    memset(table, 1, sizeof(int) * MAX * MAX);

    int ta, tb, tc;

    for (int i = 0; i < r; i++) {
        cin >> ta >> tb >> tc;
        table[ta][tb] = table[tb][ta] = tc;
    }
    for (int i = 1; i <= n; i++) table[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (table[i][k] + table[k][j] < table[i][j]) {
                    table[i][j] = table[i][k] + table[k][j];
                }
            }
        }
    }

    int maxCount = 0;
    for (int i = 1; i <= n; i++) {
        int tmpCount = 0;
        for (int j = 1; j <= n; j++) {
            if (table[i][j] <= m) tmpCount += item[j];
        }
        maxCount = max(maxCount, tmpCount);
    }

    cout << maxCount << endl;

    return 0;
}
