#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const lld LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,-1,0,1 };

int h, w;
int a[1501][1501];
bool v[1501][1501];
int D[1501][1501];

queue<ii> q;

int gr[2250001];

int _find(int g) {
    if (gr[g] == g) return g;
    return gr[g] = _find(gr[g]);
}

// u <- v
bool _union(int u, int v) {
    u = _find(u);
    v = _find(v);
    if (u == v) return true;
    gr[v] = u;
    return false;
}

int id(int y, int x) {
    return y * w + x;
}

void dfs(int y, int x, int c) {
    a[y][x] = c;
    D[y][x] = 0;
    q.push(ii(y, x));
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w || a[ny][nx] == 0 || D[ny][nx] == 0) continue;
        _union(id(y, x), id(ny, nx));
        dfs(y + dy[i], x + dx[i], c);
    }
}

int main() {
    memset(D, 0x3f, sizeof(D));

    scanf("%d %d", &h, &w);

    int ln = 0, L[2];

    for (int i = 0; i < h; ++i) {
        char s[1501];
        scanf("%s", s);
        for (int j = 0; j < w; ++j) {
            if (s[j] == 'X') a[i][j] = 0;
            else {
                a[i][j] = 1;
                if (s[j] == 'L') L[ln++] = id(i, j);
            }
            gr[id(i, j)] = id(i, j);
        }
    }

    int colors = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == 1 && !v[i][j]) {
                dfs(i, j, ++colors);
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
            a[i][j] = a[i][j] > 1 ? a[i][j] - 1 : 0;
    }

    int dist = 0;
    while (!q.empty()) {
        ++dist;
        int qs = q.size();
        while (qs--) {
            int y = q.front().first;
            int x = q.front().second;
            int c = id(y, x);
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                _union(c, id(ny, nx));
                if (a[ny][nx] == 0) {
                    D[ny][nx] = D[y][x] + 1;
                    a[ny][nx] = a[y][x];
                    q.push(make_pair(ny, nx));
                }
                else if (a[ny][nx] != a[y][x] && _find(L[0]) == _find(L[1])) {
                    printf("%d\n", max(D[y][x], D[ny][nx]));
                    return 0;
                }
            }
        }
    }

    return 0;
}