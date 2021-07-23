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
    bool isSymmetric(TreeNode* root) {
        bool ret = true;
        queue<TreeNode*> lq, rq;

        lq.push(root);
        rq.push(root);

        while (!lq.empty() && !rq.empty()) {
            TreeNode* ln, * rn;
            ln = lq.front(); lq.pop();
            rn = rq.front(); rq.pop();

            if (ln->val != rn->val) {
                return false;
            }

            if (ln->left && rn->right) {
                lq.push(ln->left);
                rq.push(rn->right);
            }
            else if (ln->left || rn->right) return false;

            if (ln->right && rn->left) {
                lq.push(ln->right);
                rq.push(rn->left);
            }
            else if (ln->right || rn->left) return false;
        }
        return ret;
    }
};