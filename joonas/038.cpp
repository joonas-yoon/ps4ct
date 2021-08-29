#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> x;
    x.push(s[0]);
    for (int i = 1; i < s.length(); ++i) {
        if(!x.empty() && x.top() == s[i]) x.pop();
        else x.push(s[i]);
    }
    return x.empty();
}