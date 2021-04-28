#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int g[500][500];

int solve() {
    memset(g, 0x3f, sizeof(g));
    int n, m, w;
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 0; i < n; ++i) g[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        g[a - 1][b - 1] = min(g[a - 1][b - 1], t);
        g[b - 1][a - 1] = min(g[b - 1][a - 1], t);
    }
    for (int i = 0; i < w; ++i) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        if (a == b) return puts("YES"), 0;
        g[a - 1][b - 1] = min(g[a - 1][b - 1], -t);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (g[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (g[i][i] < 0) return puts("YES"), 0;
    }
    puts("NO");
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}