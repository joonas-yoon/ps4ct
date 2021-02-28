#include <algorithm>
#include <vector>
using namespace std;

typedef long long lld;

const int INF = 0x3f3f3f3f;

lld calc(lld a, int o, lld b) {
    if (o == 0) return a + b;
    if (o == 1) return a - b;
    if (o == 2) return a * b;
    return a / b;
}

int goal;
vector<int> op;

bool solve(vector<int>& nums, int k) {
    if (k >= nums.size()) {
        int sum = nums[0];
        for (int i = 1; i < k; ++i) {
            sum = calc(sum, op[i - 1], nums[i]);
        }
        return sum == goal;
    }
    for (int i = 0; i < 4; ++i) {
        op.push_back(i);
        if (solve(nums, k + 1)) return true;
        op.pop_back();
    }
    return false;
}

int solution(int n, int number) {
    goal = number;
    int answer = INF;
    for (int len = 0; len < 8; ++len) {
        for (int i = (1 << len) - 1; i >= 0; --i) {
            vector<int> v;
            int k = 0;
            for (int j = 0; j <= len; ++j) {
                k = 10 * k + n;
                if (i & (1 << j)) {
                    v.push_back(k);
                    k = 0;
                }
            }
            if (k) v.push_back(k);
            op.clear();
            if (solve(v, 1)) return len + 1;
            v[0] *= -1;
            if (solve(v, 1)) return len + 1;
        }
    }
    if (answer > 8) return -1;
    return answer;
}