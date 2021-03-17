#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    bool arr[10] = { 0, };

    bool check(int idx) {
        if (!arr[idx]) return true;
        else return false;
    }

    vector<int> ret() {
        vector<int> r;
        for (int i = 1; i <= 9; i++) {
            if (!arr[i]) r.push_back(i);
        }
        return r;
    }
}node;

node hor[9], ver[9], square[9];
vector < pair<int, int> > v;
int vs, tab[9][9] = { 0, };

bool solved = false;

void solve(int idx) {
    if (idx == vs) {
        solved = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << tab[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
    }

    int vi = v[idx].first, hi = v[idx].second;
    vector<int> tmp = ver[vi].ret();

    for (auto& it : tmp) {
        if (solved) return;
        if (hor[hi].check(it) && square[(vi / 3) * 3 + hi / 3].check(it)) {
            ver[vi].arr[it] = true;
            hor[hi].arr[it] = true;
            square[(vi / 3) * 3 + hi / 3].arr[it] = true;
            tab[vi][hi] = it;

            solve(idx + 1);
            if (solved) return;

            ver[vi].arr[it] = false;
            hor[hi].arr[it] = false;
            square[(vi / 3) * 3 + hi / 3].arr[it] = false;
            tab[vi][hi] = 0;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tmp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> tmp;
            ver[i].arr[tmp] = true;
            hor[j].arr[tmp] = true;
            square[(i / 3) * 3 + j / 3].arr[tmp] = true;
            tab[i][j] = tmp;

            if (tmp == 0) v.push_back({ i, j });
        }
    }

    vs = v.size();
    solve(0);

    return 0;
}