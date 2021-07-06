#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0, 1, -1 };

int solution(vector<vector<int>> land, int height) {
    int len = land.size();
    vector<vector<int>> visit(len, vector<int>(len));
    queue<pair<int, int>> q;

    int sx = 0, sy = 0;
    int color = 0;
    int answer = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        color--;
        q.push({ sx, sy });
        answer += visit[sx][sy];
        visit[sx][sy] = color;

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (nx >= 0 && nx < len && ny >= 0 && ny < len) {
                    int tmp = visit[nx][ny];
                    int tmpN = abs(land[nx][ny] - land[cx][cy]);
                    if (tmp >= 0) {
                        if (tmpN <= height) {
                            visit[nx][ny] = color;
                            q.push({ nx, ny });
                        }
                        else {
                            if (!tmp) visit[nx][ny] = tmpN;
                            else visit[nx][ny] = min(tmp, tmpN);
                        }
                    }
                }
            }
        }

        int tmp = 987654321;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int t = visit[i][j];
                if (t > 0 && tmp > t) {
                    tmp = t;
                    sx = i;
                    sy = j;
                }
                if (t >= 0) flag = true;
            }
        }
    }

    return answer;
}