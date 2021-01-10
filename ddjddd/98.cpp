#include <iostream>
#define MAXCHILD 10

using namespace std;

struct node {
    node *child[MAXCHILD];
    bool terminal;
}arr[100007];

int idx;
bool ans = true;

node* myalloc() {
    node *ret = &arr[idx];
    for(int i = 0; i < MAXCHILD; i++) {
        ret->child[i] = 0;
    }
    ret->terminal = false;
    idx++;
    return ret;
}

void insert(char* str, node* root) {
    char* c = str;
    node* cur = root;
    node* nNode = 0;

    while(*c != '\0') {
        if(cur->terminal) {
            ans = false;
            return;
        }
        if(cur->child[(*c)-'0'] == 0) {
            nNode = myalloc();
            cur->child[(*c) - '0'] = nNode;
        }
        else {
            nNode = cur->child[(*c) - '0'];
        }
        cur = nNode;
        c++;
    }
    cur->terminal = true;
    for(int i = 9; i >= 0; i--) {
        if(cur->child[i]) {
            ans = false;
            return;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int tC; cin >> tC;
    for(int tc = 1; tc <= tC; tc++) {
        int n; cin >> n;
        idx = 0;
        ans = true;

        node* root = myalloc();
        for(int i = 0; i < n; i++) {
            char buf[11];
            buf[0] = 0;
            cin >> buf;
            if(ans) {
                insert(buf, root);
            }
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}