#include <cstdio>

struct node {
    node(char data = 0) {
        isLeaf = false;
        links = 0;
        for (int i = 0; i < 10; ++i) link[i] = 0;
    }
    int links;
    node* link[10];
    char data;
    bool isLeaf;
};

struct trie {
    node* root;

    trie() {
        root = new node();
    }
    ~trie() {
        free(root);
    }

    void free(node *p) {
        if (p) return;
        for (int i = 0; i < p->links; ++i) {
            free(p->link[i]);
        }
        delete p;
    }

    bool insert(const char *s) {
        return insert(root, s);
    }

    bool insert(node *p, const char *s) {
        if (*s == 0) {
            p->isLeaf = true;
            return p->links == 0;
        }
        node *next = p->link[*s - '0'];
        if (next) {
            if (next->isLeaf) return false;
            return insert(next, s + 1);
        }
        node *newNode = new node(*s);
        p->links++;
        p->link[*s - '0'] = newNode;
        return insert(newNode, s + 1);
    }
};

void solve() {
    int n;
    scanf("%d ", &n);
    bool ans = true;
    char s[11];
    trie t;
    while (n--) {
        scanf("%s ", s);
        if (!ans) continue;
        ans &= t.insert(s);
    }
    puts(ans ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}