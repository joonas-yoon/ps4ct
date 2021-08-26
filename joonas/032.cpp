#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> f(50005, 0);
    for (int x, i = 0; i < n; ++i) {
        scanf("%d", &x);
        f[x] += 1;
    }
    int ans = 0;
    for (int i = 1; i <= 50000; ++i) ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}