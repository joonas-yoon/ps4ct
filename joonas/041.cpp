#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long lld;
typedef pair<int, int> ii;

int n;
int a[100001];
int c[100001];

vector<ii> x; // (val, idx)

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        x.push_back(ii(a[i], i));
    }
    sort(all(x));
    bool v[100001] = {};

    lld answer = 0;
    for (auto& i : x) {
        lld cnt = 0;
        for (int j = i.second; j < n - 1 && !v[j]; ++j) {
            cnt += c[j];
            v[j] = true;
        }
        answer += cnt * i.first;
    }
    printf("%lld\n", answer);

    return 0;
}