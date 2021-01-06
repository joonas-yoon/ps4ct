#include <iostream>

using namespace std;


int r, c, q;
int sx, sy, lx, ly, ret;
unsigned int arr[1007][1007] = {0, };

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> q;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            int tmp; cin >> tmp;
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + tmp;            
        }
    }

    for(int tc = 0; tc < q; tc++) {
        cin >> sx >> sy >> lx >> ly;
        ret = (arr[lx][ly] - arr[sx-1][ly] - arr[lx][sy-1] + arr[sx-1][sy-1]) / ((lx-sx+1)*(ly-sy+1));
        cout << ret << endl;
    }

    return 0;
}