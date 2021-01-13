#include <iostream>

using namespace std;

struct node {
	int child[51];
	int si = 0;
	int id;
};

node arr[51];
int n, del, ans = 0;

void search(int cur) {
	if (arr[cur].id == del) return;
	if (arr[cur].si == 0) ans++;
	else {
		if (arr[cur].si == 1 && arr[cur].child[0] == del) ans++;
		else {
			for (int i = 0; i < arr[cur].si; i++) {
				search(arr[cur].child[i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	
	cin >> n;
	int root;
	for (int i = 0; i < n; i++) {
		arr[i].id = i;
		int t; cin >> t;
		if (t != -1) {
			arr[t].child[arr[t].si++] = i;
		}
		else {
			root = i;
		}
	}
	cin >> del;

	search(root);
	if (del == root) ans = 0;
	else if (ans <= 0) ans = 1;
	
	cout << ans << endl;

	return 0;
}