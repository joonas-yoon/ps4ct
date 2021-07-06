#include <string>
#include <vector>

using namespace std;

int dt(int n) {
    int ret = 0;
    while(n) {
        n /= 10;
        ret++;
    }
    return ret;
}

int solve(int len, char* str, int slen){
    char* c = str;
    int pos = 0;
    int ret = 0;

    while(pos < slen) {
        int cnt = 0;
        bool flag = false;
        char *sA, *sB;
        while (!flag && pos + len*2 - 1 < slen) {
            sA = c + pos;
            sB = sA + len;

            for(int i = 0; i < len; i++) {
                if(*(sA+i) != *(sB+i)) {
                    flag = true;
                    break;
                }
            }
            
            if(flag) break;
            cnt++;
            pos += len;
        }
        
        ret += len + (cnt ? dt(cnt+1) : 0);        
        pos += len;

        if(pos >= slen) {
            pos -= len;
            ret -= len;
            ret += slen - pos;
            break;
        }
    }
    return ret;
}

int solution(string s) {
    const char* str = s.c_str();
    int len = s.length();
    int plen = len / 2;

    int answer = solve(1, (char*)str, len);
    for(int i = 2; i <= plen; i++) {
        int tmp = solve(i, (char*)str, len);
        answer = tmp < answer ? tmp : answer;
    }
    return answer;
}