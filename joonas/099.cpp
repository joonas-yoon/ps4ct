#include <string>
#include <vector>
#include <cstring> // strncmp

using namespace std;

const int INF = 0x3f3f3f3f;

int solution(string s) {
    int answer = INF;
    int len = s.length();
    if (len == 1) return 1;
    const char *p = s.c_str();
    
    // k: 단위 문자열의 길이
    // 단위 문자열은 문자열의 길이의 절반을 넘을 수 없다. ("aabb" 가 최대이기 때문)
    for (int k = 1; 2 * k <= len; ++k) {
        int cur = 0, total = len, cnt = 0;
        // k자씩 묶어서 건너뛰며 비교를 한다.
        for (int i = k; i < len; i += k) {
            // 다른 (압축할 수 없는) 문자열이면 계산
            if (strncmp(p + cur, p + i, k)) {
                // 그동안 같았던 문자열의 길이만큼 짧아짐
                total -= cnt * k;
                // 숫자표기만큼 길이 늘어남. "abab"(4) -> "2"(1) + "ab"(2)
                for (; ++cnt > 1; cnt /= 10) total++;
                cnt = 0;
                cur = i;
            }
            // 같은 문자열의 경우 수만 세고 넘어감 
            else {
                cnt += 1;
            }
        }
        // 남았던 것 처리
        total -= cnt * k;
        for (; ++cnt > 1; cnt /= 10) total++;
        answer = total < answer ? total : answer;
    }
    return answer;
}
