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
    vector<int> findValueMostElement(TreeNode* root) {
        vector<int> maxs;

        if (root) myHelper(root, 0, maxs);

        return maxs;
    }

private:
    void myHelper(const TreeNode* node, const int level, vector<int>& maxs) {
        if (level == maxs.size()) maxs.push_back(std::numeric_limits<int>::min());
        if (node->val > maxs[level]) maxs[level] = node->val;

        if (node->left) myHelper(node->left, level + 1, maxs);
        if (node->right) myHelper(node->right, level + 1, maxs);
    }
};
