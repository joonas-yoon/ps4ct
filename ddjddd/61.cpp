#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int n, int m, vector<vector<int>>& tab) {
    int ret = 1;
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    vector<vector<bool>> visit2(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    q.push({ { 0, 0 }, {false, 0} });
    visit[0][0] = true;

    int ans = -1;

    while (!q.empty()) {
        int ci = q.front().first.first;
        int cj = q.front().first.second;
        bool wall = q.front().second.first;
        int dist = q.front().second.second;
        q.pop();

        if (ci == n - 1 && cj == m - 1) {
            if (ans != -1) ans = min(ans, dist + 1);
            else ans = dist + 1;
        }

        for (int i = 0; i < 4; i++) {
            int ni = ci + dx[i];
            int nj = cj + dy[i];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (!wall) {
                    if (tab[ni][nj] == 0 && !visit[ni][nj]) {
                        q.push({ { ni, nj }, { false, dist + 1 } });
                        visit[ni][nj] = true;
                    }
                    else if (!visit2[ni][nj]) {
                        q.push({ { ni, nj }, { true, dist + 1 } });
                        visit2[ni][nj] = true;
                    }
                }
                else {
                    if (tab[ni][nj] == 0 && !visit2[ni][nj]) {
                        q.push({ { ni, nj }, { true, dist + 1 } });
                        visit2[ni][nj] = true;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> tab(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            tab[i][j] = s[j] - '0';
        }
    }

    dfs(n, m, tab);
    return 0;
}