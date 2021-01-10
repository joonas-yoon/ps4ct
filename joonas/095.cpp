#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> numbers, int target) {
    int cnt[2010] = {};
    
    queue<pair<int, int>> q;
    q.push(make_pair(-1, 0));
    while (!q.empty()) {
        int i = q.front().first;
        int v = q.front().second;
        q.pop();
        
        // leaf
        if (i + 1 >= numbers.size()) {
            cnt[v + 1000] += 1;
            continue;
        }
        
        int num = numbers[i+1];
        q.push(make_pair(i + 1, v + num));
        q.push(make_pair(i + 1, v - num));
    }
    
    return cnt[target + 1000];
}