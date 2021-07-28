#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n;
vector<ll> vs, vc;

void solve() {
    int start = 0;
    ll ans = 0;
    while(start < n-1) {
        ll tstart = vc[start];
        ll tsum = vs[start];
        while(start < n-2 && tstart < vc[start+1]) {
            tsum += vs[start+1];
            start++;
        }
        ans += tsum * tstart;
        start++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vs.resize(n-1);
    vc.resize(n-1);
    for(int i = 0; i < n-1; i++) cin >> vs[i];
    for(int i = 0; i < n-1; i++) cin >> vc[i];

    solve();

    return 0;
}