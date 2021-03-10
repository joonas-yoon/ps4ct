#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

priority_queue < pair<int, int> > pq;

vector <pair<int, pair<int, int> > > v;
vector <int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c;
    cin >> n;

    map<int, int> x;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v.push_back({ a, {b, c} });
        p.push_back(a);
        p.push_back(c);
    }

    sort(v.begin(), v.end());
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());


    int cur = 0, i = 0;
    for (auto& it : p) {
        while (i < n && v[i].first <= it) {
            pq.push(v[i].second);
            i++;
        }

        int nheight = 0;
        while (!pq.empty()) {
            if (pq.top().second <= it) {
                pq.pop();
            }
            else if (pq.top().first > nheight) {
                nheight = pq.top().first;
                break;
            }
        }

        if (nheight != cur) {
            cur = nheight;
            cout << it << ' ' << cur << ' ';
        }
    }
    cout << endl;

    return 0;
}