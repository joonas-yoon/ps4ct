#include <string>
#include <vector>
#include <cstring>

using namespace std;

void convert(char* str) {
    int i, j = 0;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == '#')  {
            str[j-1] += -'A'+'a';
        }
        else{
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}


string solution(string m, vector<string> musicinfos) {
    int a, b, c, d;
    char title[65], melody[3000];
    vector< pair<int, string> > tmp;

    char* tm = (char*)m.c_str();
    convert(tm);
    int len = strlen(tm);
    for(auto& str: musicinfos) {
        title[0] = 0; melody[0] = 0;
        sscanf(str.c_str(), "%d:%d,%d:%d,%[^,],%s", &a, &b, &c, &d, title, melody);
        int start = 60*a + b, end = 60*c + d, duration = end - start;
        if(duration < len) continue;
        convert(melody);
        int i, tlen;
        i = tlen = strlen(melody);
        while(i < 1440) {
            melody[i] = melody[i%tlen];
            i++;
        }
        melody[i] = 0;
        if(duration < strlen(melody)) melody[duration] = 0;
        bool flag = strstr(melody, tm);
        if(flag) tmp.push_back({duration, title});
    }

    string answer = "(None)";
    int min = 0;
    if(tmp.size()) {
        min = tmp[0].first;
        answer = tmp[0].second;
        for(auto& v: tmp) {
            if(v.first > min) {
                min = v.first;
                answer = v.second;
            }
        }
    }

    return answer;
}