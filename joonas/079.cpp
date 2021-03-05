#include <bits/stdc++.h>
using namespace std;

string n;
map<int, int> digit;

int solve(string num) {
    if (num.length() >= n.length()) return num == n;

    int ans = 0;
    for (auto& d : digit) {
        if (!d.second) continue;
        d.second -= 1;
        string x = string(1, d.first + '0');
        ans += solve(x + num); // left
        if (x + num != num + x) ans += solve(num + x); // right
        d.second += 1;
    }

    return ans;
}

int main() {
    cin >> n;
    for (auto& c : n) {
        digit[c - '0'] += 1;
    }
    cout << solve("");
    return 0;
}