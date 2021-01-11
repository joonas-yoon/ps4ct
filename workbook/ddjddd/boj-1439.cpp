#include <iostream>
#include <cstring>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char buf[1000007];
    cin >> buf;

    int len = strlen(buf);
    int ans = 0;
    char init = buf[0];
    bool isSerial = false;
    for(int i = 1; i < len; i++) {
        if(buf[i] != init && !isSerial) {
            ans++;
            isSerial = true;
        }

        if(isSerial && buf[i] == init) {
            isSerial = false;
        }
    }
    cout << ans << '\n';

    return 0;
}