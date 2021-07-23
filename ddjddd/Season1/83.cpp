#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector < pair< pair<ll, ll>, int> > v;
vector <int> answer;

ll n;
int m;

void solve() {
    sort(v.begin(), v.end());
    auto& cur = v[0];
    answer.push_back(cur.second);
    for(auto& i: v) {
        if(-cur.first.second < -i.first.second) {
            answer.push_back(i.second);
            cur = i;
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        if(a < b) v.push_back({{a, -b}, i});
        else {
            v.push_back({{-n+a, -b}, i});
            v.push_back({{a, -(n+b)}, i});
        }
    }
    solve();

    for(auto& i:answer) cout << i << ' ';
    cout << endl;

    return 0;
}