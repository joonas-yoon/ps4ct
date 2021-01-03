#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

map<string, int> mbti;

int dist(string a, string b) {
    int r = 0;
    for (int i=0; i<4; ++i) {
        r += a[i] != b[i];
    }
    return r;
}

bool vis[16];

int dfs(string first, string cur, int k) {
    if (k >= 3) return dist(first, cur);
    int ret = INF;
    int i = -1;
    for (auto& p : mbti) {
        if (vis[++i] || p.second == 0) continue;
        vis[i] = true;
        ret = min(ret, dist(cur, p.first) + dfs(first, p.first, k + p.second));
        vis[i] = false;
    }
    return ret;
}

void solve() {
    for(auto& m : mbti) {
        m.second = 0;
    }

    int n;
    scanf("%d", &n);
    vector<string> s;
    for (int i=0; i<n; ++i) {
        char _s[5];
        scanf("%s", _s);
        s.push_back(_s);
        mbti[_s] += 1;
    }

    int ans = INF;
    for(auto& m : mbti) {
        memset(vis, 0, sizeof(vis));
        ans = min(ans, dfs(m.first, m.first, 0));
    }
    printf("%d\n", ans);
}

int main() {
    for(int m=0; m<2; ++m){
        for(int b=0; b<2; ++b){
            for(int t=0; t<2; ++t){
                for(int i=0; i<2; ++i){
                    string x = { "IE"[m], "SN"[b], "TF"[t], "JP"[i] };
                    mbti[x] = 0;
                }
            }
        }
    }

    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}