/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        return myHelper(nums.data(), nums.data() + nums.size() - 1);
    }

private:
    TreeNode* myHelper(const int* begin, const int* end) {
        if (begin == end) return new TreeNode(*begin);

        auto p = begin + (end - begin) / 2;
        auto root = new TreeNode(*p);

        if (p > begin) root->left = myHelper(begin, p - 1);
        if (p < end) root->right = myHelper(p + 1, end);

        return root;
    }
};
