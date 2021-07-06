#include <string>
#include <vector>
#include <set>

using namespace std;

set <int> v[9];

int solution(int N, int number) {
    int cur = 0;
    for(int i = 1; i < 9; i++) {
        cur = cur*10+N;
        v[i].insert(cur);

        for(int j = i-1; j > 0; j--) {
            for(auto& vi: v[j]) {
                for(auto& vj: v[i-j]) {
                    v[i].insert(vi+vj);
                    v[i].insert(vi-vj);
                    v[i].insert(vi*vj);
                    if(vj) v[i].insert(vi/vj);
                }
            }
        }
    }
    int answer = -1;

    for(int i = 1; i <= 8; i++) {
        for(auto& t: v[i]) {
            if(t == number) return i;
        }
    }

    return answer;
}