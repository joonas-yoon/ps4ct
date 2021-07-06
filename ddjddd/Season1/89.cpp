#include <string>
#include <vector>

using namespace std;

string ans;

void solve(int input) {
    if(input == 1) return;
    int tmp = input % 3;
    string here;
    if(tmp==0) here = '2';
    else if(tmp==1) here = '4';
    else if(tmp==2) here = '1';
    ans = here + ans;
    solve((input-2)/3+1);
}

string solution(int n) {
    solve(n+1);
    return ans;
}