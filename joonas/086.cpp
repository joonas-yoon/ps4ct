#include <string>
#include <algorithm>
#include <set>
using namespace std;

bool isAlphabet(char c) {
    if ('a' <= c && c <= 'z') return true;
    return 'A' <= c && c <= 'Z';
}

char toLower(char c) {
    if ('a' <= c && c <= 'z') return c;
    return c - 'A' + 'a';
}

string str(int n) {
    if (n == 0) return "0";
    string r;
    for (; n > 0; n /= 10) {
        r = string(1, (n % 10) + '0') + r;
    }
    return r;
}

int solution(string a, string b) {
    multiset<string> msa, msb;
    set<string> sa, sb, sum;
    for (int i = 1; i < a.length(); ++i) {
        if (!isAlphabet(a[i - 1]) || !isAlphabet(a[i])) continue;
        string x = string(1, toLower(a[i - 1])) + string(1, toLower(a[i]));
        msa.insert(x);
        x += str(msa.count(x));
        sa.insert(x);
        sum.insert(x);
    }

    for (int i = 1; i < b.length(); ++i) {
        if (!isAlphabet(b[i - 1]) || !isAlphabet(b[i])) continue;
        string x = string(1, toLower(b[i - 1])) + string(1, toLower(b[i]));
        msb.insert(x);
        x += str(msb.count(x));
        sb.insert(x);
        sum.insert(x);
    }

    int s = sum.size();
    if (s == 0) return 65536;
    int inter = 0;
    for (auto& x : sa) inter += sb.count(x);
    return inter * 65536 / s;
}