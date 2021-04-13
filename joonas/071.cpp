#include <string>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int count1s(int n) {
    int r = 0;
    for (; n; n &= n - 1) ++r;
    return r;
}

string bit2str(int bit) {
    string s;
    for (int j = 0; bit && j < 26; ++j, bit >>= 1) {
        if (bit & 1) s.push_back('A' + j);
    }
    return s;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<int> orderBits;
    for (auto& order : orders) {
        int bit = 0;
        for (auto& ch : order) bit |= 1 << (ch - 'A');
        orderBits.push_back(bit);
    }

    bool chk[27] = {};
    for (auto& menu : course) chk[menu] = true;

    int maxCount[20] = {};
    vector<int> res[20];

    for (int bit = (1 << 26) - 1; bit > 2; --bit) {
        int menu = count1s(bit);
        if (!chk[menu]) continue;
        int cnt = 0;
        for (auto& o : orderBits) cnt += (o & bit) == bit;
        if (cnt >= 2 && cnt >= maxCount[menu]) {
            if (cnt > maxCount[menu]) res[menu].clear();
            maxCount[menu] = cnt;
            res[menu].push_back(bit);
        }
    }

    vector<string> answer;
    for (auto& menu : course) {
        for (auto& bit : res[menu]) {
            answer.push_back(bit2str(bit));
        }
    }
    sort(all(answer));
    return answer;
}