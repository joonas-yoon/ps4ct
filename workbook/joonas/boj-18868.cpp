#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> unv;
    for(int i=0; i<n; ++i){
        vector<int> g(m);
        for(int j=0; j<m; ++j) scanf("%d", &g[j]);
        vector<int> v(g);
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        for(int j=0; j<m; ++j) g[j] = (int)(lower_bound(all(v), g[j]) - v.begin());
        unv.push_back(g);
    }

    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            ans += unv[i] == unv[j];
        }
    }
    printf("%d\n", ans);

    return 0;
}