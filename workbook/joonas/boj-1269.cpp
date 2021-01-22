#include <bits/stdc++.h>
using namespace std;

int sub(auto& a, auto& b) {
    int cnt = 0;
    for(auto& x : a) cnt += b.find(x) == b.end();
    return cnt;
}

int main() {
    int n, m;
    set<int> a, b;
    scanf("%d %d", &n, &m);
    for(int x, i=0; i<n; ++i) scanf("%d", &x), a.insert(x);
    for(int x, i=0; i<m; ++i) scanf("%d", &x), b.insert(x);
    printf("%d\n", sub(a, b) + sub(b, a));
    return 0;
}