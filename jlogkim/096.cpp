#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(),rocks.end());
    int min=1;
    int max = distance/(rocks.size()-2+1-n);
    int mid;
    int deleted=0;
    int prepointer=0;
    while(min<=max){//등호 여부 
        mid=(min+max)/2;
        deleted=0;
        prepointer=0;
        for(int i=0;i<rocks.size();i++){
            if((rocks[i]-prepointer)<mid){
                deleted++;
            }else{
                prepointer=rocks[i];
            }
        }
        if(deleted>n){
            max=mid-1;
        }else{
            answer=mid;
            min=mid+1;
        }
        //cout<<mid;
    }
    return answer;
}