#include <cstdio>

typedef long long lld;

lld a[1001][1001];

int main() {
    int r, c, q;
    scanf("%d %d %d", &r, &c, &q);
    for(int i=1; i<=r; ++i){
        for(int j=1; j<=c; ++j){
            scanf("%lld", &a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    while(q--) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        lld sum = a[r2][c2] - a[r1-1][c2] - a[r2][c1-1] + a[r1-1][c1-1];
        printf("%lld\n", sum / (r2-r1+1) / (c2-c1+1));
    }

    return 0;
}