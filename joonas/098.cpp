#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        vector<string> v;
        char _s[15];
        for(int i = 0; i < n; ++i){
            scanf("%s", _s);
            v.push_back(_s);
        }
        std::sort(v.begin(), v.end());
        bool ans = true;
        for(int i = 1; i < n; ++i){
            if (v[i-1] == v[i].substr(0, v[i-1].length())) {
                ans = false;
                break;
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}