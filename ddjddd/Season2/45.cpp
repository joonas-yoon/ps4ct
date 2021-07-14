#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;
typedef pair<int, int> myTime;

string i2s(int _input) {
    char buf[9];
    sprintf(buf, "%02d:%02d:%02d", _input/3600, _input%3600/60, _input%60);
    string ret = buf;
    return ret;
}

int s2i(string _input) {
    int h, m, s;
    sscanf(_input.c_str(), "%d:%d:%d", &h, &m, &s);
    return h*3600 + m*60 + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int h, m, s, hh, mm, ss;
    int playt = s2i(play_time);
    int advt = s2i(adv_time);

    long long viewCount[360000] = { 0, };
    for(auto& st: logs) {
        myTime tmp;
        tmp.first = s2i(st.substr(0, 8));
        tmp.second = s2i(st.substr(9, 8));

        for(int i = tmp.first; i < tmp.second; i++) {
            viewCount[i]++;
        }
    }

    long long prevSum = 0;
    int ansTime = 0;
    for(int i = 0; i < advt; i++) {
        prevSum += viewCount[i];
    }
    int len = playt-advt+1;

    long long tm = prevSum;
    for(int i = 1; i < len; i++) {
        long long tmpSum = prevSum - viewCount[i-1] + viewCount[i-1+advt];

        if(tmpSum > tm) {
            ansTime = i;
        }
        tm = max(tm, tmpSum);
        prevSum = tmpSum;
    }

    return i2s(ansTime);
}