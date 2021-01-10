#include <iostream>
#include <stack>
#include <utility>

using namespace std;

char arr[100][11] = {0, };
bool visit[100][11];

int n, k;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool dfs(int x, int y, bool check) {
    int cnt = 0;
    int cx, cy, nx, ny;
    char val;
    stack< pair<int, int> > s;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            visit[i][j] = false;
        }
    }

    s.push({x, y});
    visit[x][y] = true;
    val = arr[x][y];

    while(!s.empty()) {
        cx = s.top().first;
        cy = s.top().second;

        s.pop();
        if(check) {
            cnt++;
            if(cnt >= k) {
                return true;
            }
        }
        else {
            arr[cx][cy] = '0';
        }

        for(int dir = 0; dir < 4; dir++) {
            nx = cx + dx[dir];
            ny = cy + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < 10) {
                if(arr[nx][ny] == val && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    s.push({nx, ny});
                }
            }
        }
    }
    return false;
}

void downward() {
    for(int j = 0; j < 10; j++) {
        int k = n-1;
        for(int i = n-1; i >= 0; i--) {
            if(arr[i][j] != '0') {
                arr[k][j] = arr[i][j]; k--;
            }
        }
        for(k; k >= 0; k--) arr[k][j] = '0';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool isChange = true;
    while (isChange) {
        isChange = false;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < 10; j++) {
                if(arr[i][j] != '0') {
                    if(dfs(i, j, true)) {
                        isChange = true;
                        dfs(i, j, false);
                    }
                }
            }
        }
        
        downward();
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}