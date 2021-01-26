#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAX 1000001
#define MOD 1000000009
typedef long long ll;
ll arr[1000001] = {0,1,2,4, };

void dp() {
    for(int i = 4; i < MAX; i++) {
        arr[i] = (((arr[i-3] + arr[i-2]) % MOD) + arr[i-1]) % MOD;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp();
    int tC; cin >> tC;
    for(int tc = 1; tc <= tC; tc++) {
        int tmp; cin >> tmp;
        cout << arr[tmp] << endl;
    }

    return 0;
}