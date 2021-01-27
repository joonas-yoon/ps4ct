#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 10007
int n;
struct node {
    node *left, *right;
}*tree;

bool isroot[MAX] = {0, };
int lmin[MAX] = {0, };
int ans[MAX] = {0, };


int post(node* cur, int tsum, int level) {
    int tl = 0, tr = 0;
    if(cur->left) tl = post(cur->left, tsum, level+1);
    if(!lmin[level]) {
        lmin[level] = tsum + tl + 1;
    }
    else {
        ans[level] = max(ans[level], tsum + tl + 1 - lmin[level] + 1);
    }
    if(cur->right) tr = post(cur->right, tsum+tl+1, level+1);
    
    return tl + tr + 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    cin >> n;
    tree = new node[n+1];
    memset(tree, 0, sizeof(node)*(n+1));

    int p, l, r;
    for(int i = 0; i < n; i++) {
        cin >> p >> l >> r;
        if(l != -1) {
            tree[p].left = &tree[l];
            isroot[l] = true;
        }
        if(r != -1) {
            tree[p].right = &tree[r];
            isroot[r] = true;
        }
    }
    int root = 0;
    for(int i = 1; i <= n; i++) if(!isroot[i]) root = i;

    post(&tree[root], 0, 1);

    int alevel = 1, adist = 1;
    for(int i = 1; i < MAX && lmin[i]; i++) {
        int tdist = ans[i];
        if(adist < tdist) {
            adist = tdist;
            alevel = i;
        }
    }

    cout << alevel << ' ' << adist << endl;

    return 0;
}