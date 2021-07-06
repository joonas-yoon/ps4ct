#include <iostream>

using namespace std;

int n, r, c;

int dimen(int n, int row, int col) {
	if(n == 0) return 0;
	n--;
	int tsum = dimen(n, row&((1<<n)-1), col&((1<<n)-1));
	return tsum + (1<<(n*2)) * ((col >> n)+2*(row >> n));
}

int main () {
	cin >> n >> r >> c;
	cout << dimen(n, r, c) << endl;
	
	return 0;
}