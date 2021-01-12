#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    queue <int> q;
    int cnt = 1;
    for(auto v : numbers) {
        for(int i = 0; i < cnt; i++) {
            int tmp = 0;
            if(!q.empty()) {
                tmp = q.front();
                q.pop();
            }
            q.push(tmp + v);
            q.push(tmp - v);
        }
        cnt *= 2;
    }

    int answer = 0;
    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        if(tmp == target) answer++;
    }

    return answer;
}