#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0, n, m, k;
	cin >> n >> m >> k;

	int t = 0;
	while (true) {
		ans++;
		if (!(n >= 2 * ans && m >= ans && (m + n - k) >= 3 * ans)) {
			ans--;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}