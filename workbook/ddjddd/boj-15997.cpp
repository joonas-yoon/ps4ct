#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

    
char arr[4][11];
double pos[4][4][4] = {0.0f, };
int tab[4][4] = {0, };

int dx[6] = {0,0,0,1,1,2};
int dy[6] = {1,2,3,2,3,3};

int choosed[4] = {0, };
double result[4] = {0.0f, };

double tsum = 0.0f;

int getI(char *c) {
    for(int i = 0; i < 4; i++) {
        if(!strcmp(c, arr[i])) return i;
    }
}

void print() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                printf("%.3lf ", pos[i][j][k]);
            }
            cout << endl;
        }
        cout << endl;
    }
}

void printtab() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << tab[i][j] << ' ';
        }
        cout << endl;
    }
}

int count(int score[4], int target) {
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        if(score[i] == target) ret++;
    }
    return ret;
}

void check(int score[4], int target, int count) {
    for(int i = 0; i < 4; i++) {
        if(score[i] == target) {
            choosed[i] = count;
        }
    }
}

int choose (int score[4]) {
    int rank = 1, target = 9, tcnt = 0;
    for(int i= 0; i < 4; i++) choosed[i] = 0;
    while (rank <= 2 && target >= 0 && tcnt < 2) {
        int tmp = count(score, target);
        if(tmp) {
            check(score, target, tmp);
            rank++;
            tcnt += tmp;
        }
        target--;
    }
    return tcnt;
}

void dfs(int depth) {
    if(depth == 6) {
        // printtab();

        int score[4] = {0, };
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(i != j) {
                    if(tab[i][j] == 1) score[i] += 3;
                    else if(tab[i][j] == 2) score[i]++;
                }
            }
            // printf("(%d) ", score[i]);
        }
        int tcnt = choose(score);
        // for(int i = 0; i < 4; i++) cout << choosed[i] << ' ';
        // printf(" <%d> ", tcnt);

        double tpos = 1.0f;
        for(int i = 0; i < 6; i++) {
            tpos *= pos[tab[dx[i]][dy[i]]][dx[i]][dy[i]];
        }
        // printf("  %.10lf\n", tpos);

        

        tsum += tpos;

        // for(int i = 0; i < 4; i++) {
        //     result[i] = 0;
        // }

        if(tcnt == 2) {
            for(int i = 0; i < 4; i++) {
                int t = choosed[i];
                if(t) {
                    result[i] += tpos;
                }
            }
        }
        else if(tcnt == 3) {
            int tm = 0;

            for(int i = 0; i < 4; i++) {
                int t = choosed[i];
                if(t == 1) {
                    result[i] += tpos;
                    tm = 1;
                }
            }
            if(tm == 1) {
                for(int i = 0; i < 4; i++) {
                    int t = choosed[i];
                    if(t == 2) {
                        result[i] += tpos / 2.0f;
                    }
                }
            }
            else {
                for(int i = 0; i < 4; i++) {
                    int t = choosed[i];
                    if(t == 3) {
                        result[i] += tpos * 2.0f / 3.0f;
                    }
                }
            }
        }
        else {
            int tm = 0;
            for(int i = 0; i < 4; i++) {
                int t = choosed[i];
                if(t == 1) {
                    result[i] += tpos;
                    tm = 1;
                }
            }
            if(tm == 1) {
                for(int i = 0; i < 4; i++) {
                    int t = choosed[i];
                    if(t == 3) {
                        result[i] += tpos / 3.0f;
                    }
                }
            }
            else {
                for(int i = 0; i < 4; i++) {
                    int t = choosed[i];
                    if(t == 4) {
                        result[i] += tpos / 2.0f;
                    }
                }
            }
        }

        // for(int i = 0; i < 4; i++) {
        //     int t = choosed[i];
        //     int tm = 0;
        //     if(t) {
        //         if(tcnt >= 3) {
        //             if(t == 1) {
        //                 result[i] += tpos;
        //                 tm = 1;
        //             }
        //             if(t == 2) result[i] += tpos / 2.0f;
        //             if(t == 3) result[i] += tpos / 3.0f * 2.0f;
        //         }
        //         else {
        //             result[i] += tpos;
        //         }
        //     }
        // }

        
        // for(int i = 0; i < 4; i++) {
        //     printf("%.10lf ", result[i]);
        // }
        // cout << endl << endl;;

        return;
    }

    for(int i = 1; i <= 3; i++) {
        tab[dx[depth]][dy[depth]] = i;
        tab[dy[depth]][dx[depth]] = 4-i;
        dfs(depth+1);
        tab[dx[depth]][dy[depth]] = 0;
        tab[dy[depth]][dx[depth]] = 0;
    }
}

int main () {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    for(int i = 0; i < 4; i++) cin >> arr[i];

    for(int i = 0; i < 6; i++) {
        char buf[2][11];
        cin >> buf[0] >> buf[1];

        int ai = getI(buf[0]), bi = getI(buf[1]);
        for(int j = 1; j <= 3; j++) cin >> pos[j][ai][bi];

        for(int j = 1; j <= 3; j++) {
            pos[j][bi][ai] = pos[4-j][ai][bi];
        }   
    }
    // print();
    dfs(0);

    for(int i = 0; i < 4; i++) {
        printf("%.10lf\n", result[i]);
    }

    // cout << tsum << endl;

    return 0;
}