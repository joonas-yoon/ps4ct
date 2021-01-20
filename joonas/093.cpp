#include <cstdio>

int z(int n, int r, int c){
    if(n == 1) return 0;
    n /= 2;
    int k = 2 * ((r / n) > 0) + (c / n > 0);
    return (n * n) * k + z(n, r % n, c % n);
}

int main() {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    printf("%d\n", z(1 << n, r, c));
    return 0;
}