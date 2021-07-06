#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct myTime {
    double from, to;
};

vector <myTime> v;

bool comp(myTime a, myTime b) {
    return a.from < b.from;
}

int solution(vector<string> lines) {
    int hh, mm;
    double ss, ter;
    for(auto& i: lines) {
        myTime tmp;
        sscanf(i.c_str(), "2016-09-15 %d:%d:%lf %lfs", &hh, &mm, &ss, &ter);
        tmp.to = (double)hh*3600.0 + (double)mm*60.0 + ss;
        tmp.from = tmp.to - ter + 0.001f;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), comp);

    int answer = 0;
    for(auto& i: v) {
        double curtime = i.from;
        int ret = 0;
        for(auto& j: v) {
            if(!(curtime+1.0 < j.from) && !(j.to < curtime))ret++;
        }
        answer = max(answer, ret);
        curtime = i.to;
        ret = 0;
        for(auto& j: v) {
            if(!(curtime+1.0 < j.from) && !(j.to < curtime))ret++;
        }
        answer = max(answer, ret);
    }
    return answer;
}