#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, k, start;
vector <int> graph[300001];
queue <int> q;
int visit[300001] = {0, };
vector <int> result;

void bfs(int start) {
    q.push(start);
    visit[start] = 0;

    while(!q.empty()) {
        int td = q.front();
        int tlen = visit[td];
        q.pop();
        for(auto& v: graph[td]) {
            if(visit[v] == -1) {
                // cout <<" td " << td << ' ' << v << endl;
                visit[v] = tlen+1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++) if(visit[i] == k) result.push_back(i);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> k >> start;
    int ta, tb;
    for(int i = 0; i < m; i++) {
        cin >> ta >> tb;
        graph[ta].push_back(tb);
    }

    memset(visit, -1, sizeof(int)*(n+1));
    bfs(start);

    if(result.size() == 0) {
        cout << -1 << endl;
    }
    else {
        sort(result.begin(), result.end());
        for(auto& v: result) cout << v << '\n';
    }

    return 0;
}
