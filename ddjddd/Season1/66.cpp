#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int arr[26] = {0, } ;
    int k = 1;
    for(auto i : skill) arr[i-'A'] = k++;


    for(auto str : skill_trees) {
        int cur = 1;
        bool flag = true;
        for(auto i : str) {
            if(arr[i-'A']) {
                if(arr[i-'A'] != cur) flag = false;
                else cur++;
            }
        }
        if(flag) answer++;
    }
    return answer;
}

int main () {
    string skill = "CBD";
    vector<string> v = {"BACDE", "CBADF", "AECB", "BDA"};

    solution(skill, v);
}