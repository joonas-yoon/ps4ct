#include <string>
#include <vector>
#include <iostream>
using namespace std;
int str_arr[20][2001];
static int Y_STB = 1000;

int getPossibleWay(vector<int> &numbers, int startindex, int goal){
    //cout<<"str_arr ["<<startindex<<"]["<<(goal+Y_STB)<<"]["<<goal<<"]"<<endl;
    if(str_arr[startindex][goal+Y_STB]!=-1){
        return str_arr[startindex][goal+Y_STB];
    }
    int answer = 0;
    if(startindex==(numbers.size()-1)){
        if(goal==numbers[startindex]||goal==-numbers[startindex]){
            answer = 1;
        }
    }else{
      answer+=getPossibleWay(numbers, startindex+1,goal-numbers[startindex]);
      answer+=getPossibleWay(numbers, startindex+1,goal+numbers[startindex]);
    }
    str_arr[startindex][goal+Y_STB]=answer;
    return answer;
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    for(int i=0;i<20;i++){
        for(int j=0; j<2001; j++){
            str_arr[i][j] = -1;
        }
    }
    answer=getPossibleWay(numbers,0,target);
    
    return answer;
}