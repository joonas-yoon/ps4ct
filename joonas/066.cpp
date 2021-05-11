#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    map<char, int> lv;
    for (int i = 0; i < skill.length(); ++i) {
        lv[skill[i]] = i;
    }
    
    int answer = 0;
    for (auto& t : skill_trees) {
        bool ans = true;
        
        int lastLv = -1;
        for (auto& c : t) {
            if (lv.find(c) == lv.end()) continue;
            if (lastLv + 1 != lv[c]) {
                ans = false;
                break;
            }
            lastLv = lv[c];
        }
        
        answer += ans;
    }
    return answer;
}