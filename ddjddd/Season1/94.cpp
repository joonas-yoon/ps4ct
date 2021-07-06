#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAX 10007

int n, ans = 0;
bool visited[MAX] = {0, };
int root = 0;

vector < pair<int, int> > tree[MAX];

void dfs(int cur, int dist) {
    if(visited[cur]) return;

    visited[cur] = true;
    if(ans < dist) {
        root = cur;
        ans = dist; // Second dfs
    }

    for(auto v : tree[cur]) {
        dfs(v.first, dist + v.second);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int parent, child, dist;
        cin >> parent >> child >> dist;
        tree[parent].push_back({child, dist});
        tree[child].push_back({parent, dist});
    }

    dfs(1, 0);
    for(int i = 0; i < MAX; i++) visited[i] = false;
    dfs(root, 0);
    cout << ans << endl;

    return 0;
}