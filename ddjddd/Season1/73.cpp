#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, c, ans = 0;
long long arr[30] = { 0, };
bool group = false;
vector<long long> v[2];

void dfs(int s, int e, long long sum) {
    if (sum > c) return;
    if (s == e) {
        v[group].push_back(sum);
        return;
    };

    dfs(s + 1, e, sum + arr[s]);
    dfs(s + 1, e, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];

    group = false;
    dfs(0, n / 2, 0);
    group = true;
    dfs(n / 2, n, 0);

    sort(v[1].begin(), v[1].end());
    for (auto& i : v[0]) {
        // 반환형이 Iterator 이므로 vector container인 경우에는
        // iterator에서 v.begin()을 뺀 값으로 몇 번째 인자인지 계산
        ans += upper_bound(v[1].begin(), v[1].end(), c - i) - v[1].begin();
    }
    cout << ans << endl;

    return 0;
}