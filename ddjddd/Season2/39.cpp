#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int t, na, nb;
vector<ll> va, vb, suma, sumb;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    cin >> na;
    va.resize(na);
    for(int i = 0; i < na; i++) cin >> va[i];
    cin >> nb;
    vb.resize(nb);
    for(int i = 0; i < nb; i++) cin >> vb[i];

    for(int i = 0; i < na; i++) {
        ll sum = va[i];
        suma.push_back(sum);
        for(int j = i+1; j < na; j++) {
            sum += va[j];
            suma.push_back(sum);
        }
    }

    for(int i = 0; i < nb; i++) {
        ll sum = vb[i];
        sumb.push_back(sum);
        for(int j = i+1; j < nb; j++) {
            sum += vb[j];
            sumb.push_back(sum);
        }
    }

    sort(sumb.begin(), sumb.end());

    ll result = 0;
    for(auto& it: suma) {
        result += upper_bound(sumb.begin(), sumb.end(), t-it) - lower_bound(sumb.begin(), sumb.end(), t-it);
    }
    cout << result << endl;

    return 0;
}