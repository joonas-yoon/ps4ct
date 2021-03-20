/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef pair<TreeNode*, char> pi;
    
    vector<pi> v;
    
    void dfs(TreeNode* p, char from) {
        if (p->left) dfs(p->left, -1);
        v.push_back(pi(p, from));
        if (p->right) dfs(p->right, 1);
    }
    
    bool sym(const pi& a, const pi& b) {
        return a.first->val == b.first->val && a.second + b.second == 0;
    }
    
    bool isSymmetric(TreeNode* root) {
        dfs(root, 0);
        int n = v.size();
        if (!(n & 1)) return false; // len(L-root-R) == odd
        for (int i=0; 2 * i < n - 1; ++i) {
            if (!sym(v[i], v[n-1-i])) return false;
        }
        return true;
    }
};