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
    // solve problem in [l, r)
    TreeNode* makeTree(vector<int>& a, int l, int r) {
        if (l >= r) return nullptr;
        int mid = (l + r) >> 1;
        auto left = makeTree(a, l, mid);
        auto right = makeTree(a, mid + 1, r);
        return new TreeNode(a[mid], left, right);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size());
    }
};