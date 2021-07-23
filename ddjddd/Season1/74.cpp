#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct node {
    int arr[3];
}v[6];

int ans = 0;
int visit[6] = { 0, };

void dfs(int depth, int recent, int init) {
    if (depth == 5) {
        int tsum = 0;
        for (int i = 0; i < 6; i++) {
            tsum += visit[i];
        }
        ans = max(ans, tsum);
        return;
    }

    for (int i = 0; i < 6; i++) {
        if (!visit[i]) {
            for (int j = 0; j < 3; j++) {
                if (v[i].arr[j] == recent) {
                    if ((depth == 4) && (init != v[i].arr[(j + 2) % 3])) {
                        continue;
                    }
                    else {
                        visit[i] = v[i].arr[(j + 1) % 3];
                        dfs(depth + 1, v[i].arr[(j + 2) % 3], init);
                        visit[i] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        ans = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) cin >> v[i].arr[j];
            visit[i] = 0;
        }

        for (int i = 0; i < 3; i++) {
            visit[0] = v[0].arr[(i + 1) % 3];
            dfs(0, v[0].arr[(i + 2) % 3], v[0].arr[i]);
            visit[0] = 0;
        }
        if (!ans) cout << "none\n";
        else cout << ans << endl;

        char buf[2]; cin >> buf;
        if (buf[0] == '$') break;
    }

    return 0;
}