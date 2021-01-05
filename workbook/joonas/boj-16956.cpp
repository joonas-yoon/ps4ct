#include <cstdio>

int h, w;
char s[505][505];

bool solve() {
    int dy[]={-1,0,1,0};
    int dx[]={0,1,0,-1};

    for (int i=1; i<=h; ++i) {
        for (int j=1; j<=w; ++j){
            if (s[i][j] != 'S') continue;
            for(int d=0; d<4; ++d){
                int y = i + dy[d];
                int x = j + dx[d];
                if (s[y][x] == 'W') return false;
                if (!s[y][x] || s[y][x] != '.') continue;
                s[y][x] = 'D';
            }
        }
    }

    return true;
}

int main() {
    scanf("%d %d", &h, &w);

    for (int i=1; i<=h; ++i) scanf("%s", &s[i][1]);

    if (solve()) {
        puts("1");
        for (int i=1; i<=h; ++i) {
            for (int j=1; j<=w; ++j) putchar(s[i][j]);
            puts("");
        }
    }
    else {
        puts("0");
    }

    return 0;
}