#include <iostream>
#include <vector>

using namespace std;

const int MAX = 501, INF = 987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tC; cin >> tC;
    for (int tc = 1; tc <= tC; tc++) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<pair<int, int> > vm[MAX];
        int dist[MAX];
        for (int i = 1; i <= n; i++) dist[i] = INF;

        int a, b, c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            vm[a].push_back({ b, c });
            vm[b].push_back({ a, c });
        }
        for (int i = 0; i < w; i++) {
            cin >> a >> b >> c;
            vm[a].push_back({ b, -c });
        }

        bool isCycle = false;
        dist[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (auto& it : vm[j]) {
                    if (dist[it.first] > it.second + dist[j]) {
                        dist[it.first] = it.second + dist[j];
                        if (i == n) isCycle = true;
                    }
                }
            }
        }

        if (isCycle) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
