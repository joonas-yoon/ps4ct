#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    // rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    int left = 0, right = distance, mid;

    while(left <= right) {
        mid = (left + right)/2;
        
        int prev = 0, remove = 0;
        for(auto i = rocks.begin(); i != rocks.end(); i++) {
            if(*i - prev < mid) remove ++;
            else prev = *i;
        }

        if(remove > n) right = mid-1;
        else left = mid+1;
    }

    answer = right;

    return answer;
}