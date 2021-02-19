#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
 
typedef long long lld;
typedef pair<int, int> ii;

vector<ii> g[2001];
 
int main() {
    int n, c, m;
    scanf("%d %d %d", &n, &c, &m);
    while (m--) {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        g[e].push_back(ii(-s, w));
    }
 
    vector<int> cap(n + 1, c);
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto& p : g[i]) {
            for (int j = -p.first; p.second && j < i; ++j) {
                p.second = min(p.second, cap[j]);
            }
            p.second *= -1;
        }
        sort(all(g[i]));
        for (auto& p : g[i]) {
            int s = -p.first, cc = -p.second;
            for (int j = s; j < i; ++j) cc = min(cc, cap[j]);
            for (int j = s; j < i; ++j) cap[j] -= cc;
            answer += cc;
        }
    }
 
    printf("%d\n", answer);
 
    return 0;
}