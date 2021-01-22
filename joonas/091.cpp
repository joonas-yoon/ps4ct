#include <cstdio>
#include <cstring>

const int MOD = 1e9 + 9;

int dp[1000001];

int g(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    int& ans = dp[n];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 1; i <= 3; ++i) {
        ans = (ans + g(n - i)) % MOD;
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", g(n));
    }
    return 0;
}