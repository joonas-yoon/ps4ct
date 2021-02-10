#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int n, m;

long long x[1007] = {0, };
long long y[1007] = {0, };
int arr[1007] = {0, };

typedef pair< pair<int, int>, double> node;
vector<node> graph;

double dist(int a, int b) {
    return sqrt(((x[a]-x[b])*(x[a]-x[b]))+((y[a]-y[b])*(y[a]-y[b])));
}

int find(int n) {
	if (arr[n] <= 0) return n;
	arr[n] = find(arr[n]);
	return arr[n];
}

void merge(int a, int b) {
	int x, y;
	x = find(a);
	y = find(b);
	if (x == y) return;
	arr[y] = x;
}

bool comp(node a, node b) {
    return a.second < b.second;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            graph.push_back({{i, j}, dist(i, j)});
        }
    }

    sort(graph.begin(), graph.end(), comp);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int ta = find(a), tb = find(b);
        if (ta != tb) {
			merge(ta, tb);
		}
    }
    double ret = 0.0;
    for(auto& v : graph) {
        int a = find(v.first.first), b = find(v.first.second);
		if (a != b) {
			merge(a, b);
            ret += v.second;
		}
    }

    printf("%.2lf\n", ret);
    return 0;
}