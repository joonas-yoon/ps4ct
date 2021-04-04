#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int idx[6]; // order
int off[6]; // offset
int a[6][3];

int calc(int pos) {
    if (pos >= 6) {
        bool matched = true;
        int ans = 0;
        for (int i = 0; matched && i < 6; ++i) {
            int cur = idx[i];
            int nxt = idx[(i + 1) % 6];
            matched &= a[cur][(off[cur] + 1) % 3] == a[nxt][off[nxt]];
            ans += a[cur][(off[cur] + 2) % 3];
        }
        return matched ? ans : -INF;
    }

    int ans = -INF;
    for (int i = 0; i < 3; ++i) {
        off[pos] = i;
        ans = max(ans, calc(pos + 1));
    }
    return ans;
}

int main() {
    while (true) {
        for (int i = 0; i < 6; ++i) {
            scanf("%d %d %d ", &a[i][0], &a[i][1], &a[i][2]);
            idx[i] = i;
        }

        int ans = -INF;
        do {
            ans = max(ans, calc(0));
        } while (next_permutation(idx, idx + 6));

        if (ans == -INF) puts("none");
        else printf("%d\n", ans);

        char _s[2];
        scanf("%s ", _s);
        if (_s[0] != '*') break;
    }

    return 0;
}