#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int node, edge, start, target;
vector <pii> graph[1001];
vector <int> ans;

const int INF = 987654321;

void solve(int start) {
    ans[start] = 0;
    priority_queue<pii> pq;
    pq.push({ ans[start], start });

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDistance = -pq.top().first;

        pq.pop();

        if (ans[cur] >= curDistance) {
            for (auto& it : graph[cur]) {
                int nextNode = it.first;
                int nextDistance = curDistance + it.second;

                if (nextDistance < ans[nextNode]) {
                    ans[nextNode] = nextDistance;
                    pq.push({ -nextDistance, nextNode });
                }
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> node >> edge;
    ans.resize(node + 1, INF);
    int a, b, dist;
    for (int i = 0; i < edge; i++) {
        cin >> a >> b >> dist;
        graph[a].push_back({ b, dist });
    }
    cin >> start >> target;

    solve(start);
    cout << ans[target] << '\n';


    return 0;
}
