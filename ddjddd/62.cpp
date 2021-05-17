#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

vector<int> v;

void dfs(int si, int sj, int n, int m, vector<vector<int>>& tab, int color) {
    int ret = 1;
    stack<pair<int, int>> s;
    s.push({ si, sj });
    tab[si][sj] = color;

    while (!s.empty()) {
        int ci = s.top().first;
        int cj = s.top().second;
        s.pop();

        for (int i = 0; i < 4; i++) {
            int ni = ci + dx[i];
            int nj = cj + dy[i];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && tab[ni][nj] == 0) {
                s.push({ ni, nj });
                tab[ni][nj] = color;
                ret++;
            }
        }
    }

    v.push_back(ret % 10);
}

void solve(int n, int m, vector<vector<int>>& tab, vector<vector<int>>& ans) {
    int color = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tab[i][j] == 0) {
                dfs(i, j, n, m, tab, color);
                color++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tab[i][j] == 1) {
                ans[i][j] = 1;
                set<int> adj;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && tab[ni][nj] != 1) {
                        adj.insert(tab[ni][nj]);
                    }
                }
                for (auto& it : adj) {
                    ans[i][j] += v[it - 2];
                    ans[i][j] %= 10;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> tab(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            tab[i][j] = s[j] - '0';
        }
    }

    solve(n, m, tab, ans);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) cout << tab[i][j];
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << ans[i][j];
        cout << endl;
    }

    return 0;
}