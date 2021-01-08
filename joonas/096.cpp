#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// delete when is less than d
int stones(vector<int>& s, int end, int d) {
    int c = 0, ret = 0;
    for (auto& x : s) {
        if (x - c < d) ret++;
        else c = x;
    }
    ret += end - c < d;
    return ret;
}

int solution(int distance, vector<int> rocks, int n) {
    std::sort(rocks.begin(), rocks.end());
    int l = 0, r = distance;
    while (l <= r) {
        int mid = (l + r) / 2;
        int s = stones(rocks, distance, mid);
        if (s <= n) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}