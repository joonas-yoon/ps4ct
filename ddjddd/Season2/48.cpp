#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int len = a.size();

    if (len <= 2) return len;

    vector<int> left(len), right(len);

    int lmin = a[0], rmin = a[len-1];
    left[0] = a[0];
    right[len-1] = a[len-1];
    for(int i = 1; i < len-1; i++) {
        left[i] = min(a[i-1], left[i-1]);
        right[len-1-i] = min(a[len-i], right[len-i]);
    }

    int answer = 2;
    for(int i = 1; i < len-1; i++) {
        if(!(a[i] > left[i] && a[i] > right[i])) {
            answer++;
        }
    }

    return answer;
}