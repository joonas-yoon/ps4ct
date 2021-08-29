#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack <char> st;

    for(auto& it: s) {
        if(st.empty()) st.push(it);
        else {
            if(it == st.top()) st.pop();
            else st.push(it);
        }
    }

    return st.empty();
}