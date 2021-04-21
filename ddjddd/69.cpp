#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // vector<int> input;
    int len = 0;

    TreeNode* findMid(int start, int end, vector<int>& input) {
        int mid = (start + end) / 2;
        TreeNode* ret = new TreeNode(input[mid]);

        if (start == end) return ret;
        if (mid - 1 >= 0 && mid - 1 >= start) {
            ret->left = findMid(start, mid - 1, input);
        }
        if (mid + 1 <= len && mid + 1 <= end) {
            ret->right = findMid(mid + 1, end, input);
        }

        return ret;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        len = nums.size() - 1;
        // input = nums;
        return findMid(0, len, nums);
    }
};