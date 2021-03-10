#include <iostream>
#include <set>
#include <string>

using namespace std;

set <string> s;
string buf;
int len, ans;

void bfs(string sub, int left, int right) {
    string ret = sub + buf.substr(left, right - left + 1);
    if (right - left == len - 2) {
        s.insert(ret);
        return;
    }
    if (left > 0) bfs(ret, left - 1, right);
    if (right < len - 1) bfs(ret, left, right + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> buf;
    len = buf.length();
    for (int i = 0; i < len; i++) bfs("", i, i);
    ans = len == 1 ? 1 : s.size();
    cout << ans << '\n';

    return 0;
}