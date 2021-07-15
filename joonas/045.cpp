#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long lld;

const int MAX_N = 100 * 60 * 60 + 5;

lld seg[(MAX_N << 2) + 1];
lld lazy[(MAX_N << 2) + 1];

void build(int len) {
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
}

lld query(int ql, int qr, int node, int left, int right) {
    if (lazy[node]) {
        if (left != right) {
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        seg[node] += lazy[node] * (right - left + 1LL);
        lazy[node] = 0;
    }
    if (qr < left || right < ql) {
        return 0;
    }
    if (ql <= left && right <= qr) {
        return seg[node];
    }
    int mid = (left + right) / 2;
    return query(ql, qr, node << 1, left, mid) + query(ql, qr, node << 1 | 1, mid + 1, right);
}

lld query(int l, int r, int len) {
    int base = 1;
    return query(base + l, base + r, base, base, len);
}

void updateRange(int ql, int qr, lld diff, int node, int left, int right) {
    if (lazy[node]) {
        if (left != right) {
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        seg[node] += lazy[node] * (right - left + 1LL);
        lazy[node] = 0;
    }
    if (qr < left || right < ql) {
        return;
    }
    if (ql <= left && right <= qr) {
        if (left != right) {
            lazy[node << 1] += diff;
            lazy[node << 1 | 1] += diff;
        }
        seg[node] += diff * (right - left + 1LL);
        return;
    }
    int mid = (left + right) / 2;
    updateRange(ql, qr, diff, node << 1, left, mid);
    updateRange(ql, qr, diff, node << 1 | 1, mid + 1, right);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

void updateRange(int l, int r, lld diff, int len) {
    int base = 1;
    updateRange(base + l, base + r, diff, base, base, len);
}

// "00" -> d
int getII(const char *s) {
    return (s[0] - '0') * 10 + s[1] - '0';
}

// "00:00:00" -> d
int toSec(string s) {
    return getII(s.data()) * 3600 + getII(s.data() + 3) * 60 + getII(s.data() + 6);
}

// d -> "00"
string makeII(int t) {
    string s = to_string(t);
    while (s.length() < 2) s = string("0") + s;
    return s;
}

// d -> "00:00:00"
string toStr(int t) {
    return makeII(t / 3600) + ":" + makeII((t / 60) % 60) + ":" + makeII(t % 60);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int n = toSec(play_time) + 1;
    build(n);

    for (auto& l : logs) {
        int start = toSec(l), end = toSec(l.substr(9)) - 1;
        updateRange(start, end, 1, n);
    }

    int adv = toSec(adv_time), idx = 0;
    lld maxV = 0;
    for (int i = 0; i < n - adv; ++i) {
        lld q = query(i, i + adv - 1, n);
        if (maxV < q) {
            maxV = q;
            idx = i;
        }
    }
    return toStr(idx);
}