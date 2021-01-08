#include <cstdio>

int main() {
    char s[1000001];
    scanf("%s ", s);
    int cnt = 0;
    for(int i=1; s[i]; ++i){
        if (s[i-1] != s[i]) {
            cnt++;
        }
    }
    printf("%d\n", (cnt + 1) / 2);
    return 0;
}