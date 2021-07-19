#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n, a[100001][2];
    int dp[100001][2];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &a[i][0], &a[i][1]);

    int ans = 1;
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i][1] = 1;
        if (a[i][0] == a[i - 1][0]) dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
        if (a[i][0] == a[i - 1][1]) dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
        if (a[i][1] == a[i - 1][0]) dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
        if (a[i][1] == a[i - 1][1]) dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);

        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    int val = INF;
    for (int i = 0; i < n; ++i) {
        if (ans == dp[i][0]) val = min(val, a[i][0]);
        if (ans == dp[i][1]) val = min(val, a[i][1]);
    }
    printf("%d %d\n", ans, val);

    return 0;
}