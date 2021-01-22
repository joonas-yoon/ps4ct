#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(),(v).end()

typedef long long lld;
typedef pair<int, int> ii;

int t[4][4][2]={}; // [a][b][c] := the result (c=0;win/c=1;draw) of a vs b,
int r[6]; // result
int e[6][2];
lld ans[4];

void calcPs(vector<int> &winner, lld p) {
    for(auto& x : winner) {
        ans[x] += p;
    }
}

void perm(int cur) {
    if (cur >= 6) {
        int point[4] = {};
        lld p = 1;
        for(int i=0; i<6; ++i) {
            int a = e[i][0], b = e[i][1];
            if (r[i] < 0) {
                point[b] += 3;
                p *= t[b][a][0];
            } else if (r[i] > 0) {
                point[a] += 3;
                p *= t[a][b][0];
            } else {
                point[a] += 1;
                point[b] += 1;
                p *= t[a][b][1];
            }
        }
        vector<ii> rank;
        for(int i=0; i<4; ++i) rank.push_back(ii(-point[i], i));
        sort(all(rank));

        vector<int> winner(1, rank[0].second);
        int w = 1;
        for(int i = 0; w < 4 && rank[i].first == rank[w].first; ++w) winner.push_back(rank[w].second); // 1st
        int st1 = winner.size();
        {
            lld pt[] = {0, p, p, 2*p/3, p/2};
            calcPs(winner, pt[st1]);
        }
        if (st1 >= 2) return; // peek 2
        winner.clear();
        for(int i = w; w < 4 && rank[i].first == rank[w].first; ++w) winner.push_back(rank[w].second); // 2st
        int nd2 = winner.size();
        {
            lld pt[] = {0, p, p, p/2, p/3};
            calcPs(winner, pt[st1 + nd2]);
        }
        return;
    }
    for (int i=-1; i<2; ++i) {
        r[cur] = i;
        perm(cur + 1);
    }
}

int main() {
    for(int i=0, k=0; i<4; ++i){
        for(int j=i+1; j<4; ++j) {
            e[k][0] = i, e[k][1] = j;
            k++;
        }
    }

    map<string, int> id;
    char s[11], p[11];
    for(int i=0; i<4; ++i){
        scanf("%s ", s);
        int sz = id.size();
        id[s] = sz;
    }
    for(int i=0; i<6; ++i){
        int w, d, l, _w, _d, _l;
        scanf("%s %s %d.%d %d.%d %d.%d", s, p, &_w, &w, &_d, &d, &_l, &l);
        w += 1000 * _w;
        d += 1000 * _d;
        l += 1000 * _l;
        int a = id[s], b = id[p];
        t[a][b][0] = w;
        t[a][b][1] = t[b][a][1] = d;
        t[b][a][0] = l;
    }

    perm(0);

    for(int i=0; i<4; ++i){
        printf("%.10lf\n", (ans[i] + 1e-12) / 1e18);
    }
    
    return 0;
}