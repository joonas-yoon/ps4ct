#include <cstdio>

bool t[(1 << 20) + 5];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    while (q--) {
        int x, ans = 0;
        scanf("%d", &x);
        for (int i = x; i; i /= 2){
            if (t[i]) ans = i;
        }
        t[x] = true;
        printf("%d\n", ans);
    }
    return 0;
}