#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAX 10007

int n;
int cost[MAX];
bool visit[MAX];
vector <int> tree[MAX];

int dp[2][MAX] = {0, };

void dfs(int cur, bool select) {
    if(dp[select][cur]) return;

    if(tree[cur].size() == 1 && visit[tree[cur][0]]) {
        visit[cur] = true;
        dp[false][cur] = 0;
        dp[true][cur] = cost[cur];

        return;
    }
    
    visit[cur] = true;
    if(select) {        
        int tmp = 0;
        for(auto& v: tree[cur]) {
            if(!visit[v]) {
                dfs(v, 0);
            }
            tmp += dp[0][v];
        }
        dp[select][cur] += tmp;
        dp[select][cur] += cost[cur];
    }
    else {
        int tmp = 0;
        for(auto& v: tree[cur]) {
            if(!visit[v]) {
                dfs(v, 0); dfs(v, 1);
                tmp += dp[0][v] > dp[1][v] ? dp[0][v] : dp[1][v];
            }
        }
        dp[select][cur] += tmp;
    }

    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 1; i < n; i++) {
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
        tree[child].push_back(parent);
    }

    dfs(1, 1);
    for(int i = 1; i <= n; i++) visit[i] = false;
    dfs(1, 0);
    int ans = dp[0][1] > dp[1][1] ? dp[0][1] : dp[1][1];
    cout << ans << endl;



    // for(int i)
    // cout << dfs(1, 1) << dfs(1, 0);

    return 0;
}