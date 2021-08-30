#include <iostream>
#include <vector>

using namespace std;

int arr[50001] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr[tmp]++;
    }

    int ans = 0;
    for(int i = 1; i <= 50000; i++) {
        ans = max(ans, arr[i]);
    }

    cout << ans << '\n';

    return 0;
}
