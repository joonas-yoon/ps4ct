#include <iostream>

using namespace std;

bool arr[1048580] = {0, };

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input.txt", "r", stdin);

    arr[1] = true;
    int n, tC; cin >> n >> tC;
    for(int tc = 0; tc < tC; tc++) {
        int tmp = 0; cin >> tmp;
        int ti = tmp;
        int ans = 0;
        while (ti > 1) {
            if(arr[ti]) { ans = ti; }
            ti = ti / 2;
        }
        if(ans == 0) arr[tmp] = true;
        cout << ans << '\n';
    }

    return 0;
}