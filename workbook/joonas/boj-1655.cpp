#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> L, R;
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        L.push(x);
        for (; L.size() > R.size(); L.pop()) R.push(-L.top());
        for (; L.size() < R.size(); R.pop()) L.push(-R.top());
        int top = L.top();
        if (L.size() == R.size()) top = min(top, -R.top());
        printf("%d\n", top);
    }
    return 0;
}