#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
    return min(a / 2, b);
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, f(n - i, m - k + i));
    }
    printf("%d\n", ans);

    return 0;
}