#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, weightSum, ans = 0;
vector < pair< int, pair<int, int> > > v;
int carry[2001] = {0, };

int solve() {
    sort(v.begin(), v.end());

    int tmp, tcarry, ans = 0;
    for(auto& i: v) {
        tmp = 0;
        for(int j = i.second.first; j < i.first; j++) {
            tmp = max(tmp, carry[j]);
        }
        tcarry = min(i.second.second, weightSum - tmp);
        ans += tcarry;
        for(int j = i.second.first; j < i.first; j++) {
            carry[j] += tcarry;
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> weightSum;
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({b, {a, c}});
    }
    cout << solve() << endl;

    return 0;
}