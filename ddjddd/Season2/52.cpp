#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int ans[6] = {0, };

    for(int i = 1; i <= 5; i++){
        for(int j = 0, cnt = 0; j < n; j++){
            if(a[j]== i || b[j] == i) cnt++;
            else cnt = 0;
            ans[i] = max(ans[i], cnt);
        }
    }

    int num = -1, grade = -1;
    for(int i = 1; i <= 5; i++) {
        if(ans[i] > num) {
            num = ans[i];
            grade = i;
        }
    }
    cout << num << ' ' << grade << '\n';

    return 0;
}