#include <string>
#include <cstring>

using namespace std;

int tab[2][26][26];

bool isLower(char* c) {
    if(*c <= 'z' && *c >= 'a') return true;
    else return false;
}

void makeTable(char* str, int idx) {
    char *ta = str, *tb = ta+1;
    while(*tb != '\0') {
        *ta = (char)tolower(*ta);
        *tb = (char)tolower(*tb);
        if(isLower(ta) && isLower(tb)) {
            tab[idx][*ta-'a'][*tb-'a']++;
        }
        ta++; tb++;
    }
}

int solution(string str1, string str2) {
    memset(tab, sizeof(int)*2*26*26, 0);
    makeTable((char*)str1.c_str(), 0); makeTable((char*)str2.c_str(), 1);

    int minSum = 0, maxSum = 0, ta, tb;
    for(int i = 0;i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            ta = tab[0][i][j], tb = tab[1][i][j];
            minSum += ta&&tb ? min(ta, tb) : 0;
            maxSum += ta||tb ? max(ta, tb) : 0;
        }
    }
    int answer = maxSum == 0 ? 65536 : (double)minSum / (double)maxSum * 65536.0;
    return answer;
}