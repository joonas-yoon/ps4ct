#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    n++;
    int** d = new int* [n];
    for (int i = 1; i < n; i++) {
        d[i] = new int[n] {};
        memset(d[i], INF, sizeof(int) * n);
    }

    for (auto& it : fares) {
        d[it[0]][it[1]] = d[it[1]][it[0]] = it[2];
    }

    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 1, j = 1;i < n; i++, j++) {
        if (i == j) d[i][j] = 0;
    }

    int answer = INF * 2;
    for (int i = 1; i < n; i++) {
        int sum = d[s][i] + d[i][a] + d[i][b];
        answer = min(answer, sum);
    }

    return answer;
}