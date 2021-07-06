#include <iostream>

using namespace std;

int n, r, c, ans = 0;

void solve(int x, int y, int len) {
	if(len == 1) {
		if(x == r && y == c) cout << ans << endl;
		ans ++;
		return;
	}
	
	else {
		len /= 2;
		
		if(x <= r && r < x + len) {
			if(y <= c && c < y + len) {
				solve(x, y, len);
			}
			else if(y + len <= c) {
				ans += 1*len*len;
				solve(x, y+len, len);
			}
		}
		else if(x+len <= r) {
			if(y <= c && c < y + len) {
				ans += 2*len*len;
				solve(x+len, y, len);
			}
			if(y + len <= c) {
				ans += 3*len*len;
				solve(x+len, y+len, len);
			}
		}
	}
}

int main () {
	cin >> n >> r >> c;
	int len = 1;
	for(int i = 0; i < n; i++) {
		len *= 2;
	}
	solve(0, 0, len);
	return 0;
}
