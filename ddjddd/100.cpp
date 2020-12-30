#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void outer(int* arr, int cur, int curSteps, int steps, int* value) {
	arr[cur] = (*value)++;
	for(int i = 0; i < steps-1; i++) {
		cur += curSteps++;
		arr[cur] = (*value)++;
	}
	for(int i = 0; i < steps-1; i++) {
		cur++;
		arr[cur] = (*value)++;
	}
	for(int i = 0; i < steps-2; i++) {
		cur -= curSteps--;
		arr[cur] = (*value)++;
	}
}

void solve(int* arr, int cur, int curSteps, int steps, int* value) {
    if(steps == 0) {
        return;
    }
    else if(steps == 1) {
        arr[cur] = (*value)++;
    }
    else if(steps == 2) {
        arr[cur] = (*value)++;
		arr[cur+curSteps] = (*value)++;
		arr[cur+curSteps+1] = (*value)++;
    }
    else {
        outer(arr, cur, curSteps, steps, value);
        solve(arr, cur+curSteps + (curSteps+1)+1, curSteps+2, steps-3, value);
    }
}

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));
    int value = 1;
    solve(answer, 0, 1, n, &value);
    
    return answer;
}