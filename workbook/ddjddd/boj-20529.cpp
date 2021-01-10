#include <iostream>

using namespace std;

int arr[16] = {0, };
int table[16][16] = {0, };
int index[3];
int ans;

void maketable() {
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            int ret = 0;
            int diff = i ^ j;
            while (diff) {
                ret += diff & 1;
                diff >>= 1;
            }
            table[i][j] = ret;
        }
    }
}

void insert(char* mbti) {
    int idx = 0;
    if(*mbti++ == 'I') idx += 8;
    if(*mbti++ == 'N') idx += 4;
    if(*mbti++ == 'F') idx += 2;
    if(*mbti++ == 'P') idx += 1;

    arr[idx]++;
    if(arr[idx] > 3) arr[idx] = 3;
}

void answer() {    
    int ret = table[index[0]][index[1]] + table[index[0]][index[2]] + table[index[1]][index[2]];
    // for(int i = 0; i < 3; i++) cout << index[i] << ' ';
    // // cout << "  here " << table[index[0]][index[1]] << ' ' << table[index[0]][index[2]] << ' ' << table[index[1]][index[2]] << '\n';
    ans = ret < ans ? ret : ans;
}

void dfs(int depth, int cur) {
    if(depth == 3) {
        answer();
        return;
    }

    for(int i = cur; i < 16; i++) {
        if(arr[i] > 0) {
            index[depth] = i;
            arr[i]--;
            dfs(depth+1, i);
            arr[i]++;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    maketable();

    int tC; cin >> tC;
    for(int tc = 1; tc <= tC; tc++) {
        int num;
        char buf [5];

        for(int i = 0; i < 16; i++) arr[i] = 0;
        ans = 9822387;

        cin >> num;
        for(int i = 0; i < num; i++) {
            cin >> buf;
            buf[4] = 0;
            insert(buf);
        }

        dfs(0, 0);
        cout << ans << endl;
    }

    return 0;
}