#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
char map[1507][1507] = {0, };
int arr[1507*1507] = {0, };

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bx[2];
int by[2];

int find(int n) {
	if (arr[n] <= 0) return n;
	arr[n] = find(arr[n]);
	return arr[n];
}

void merge(int a, int b) {
	int x, y;
	x = find(a);
	y = find(b);
	if (x == y) return;
	arr[y] = x;
}


bool bfs() {

    return false;
}

void day() {

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int pos = 0;
    for(int i = 0; i < n; i++) {
        cin >> map[i];
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 'L') {
                bx[pos] = i;
                by[pos] = j;
                break;
            }
        }
    }

    while(!bfs())  {
        day()
    }

    return 0;
}