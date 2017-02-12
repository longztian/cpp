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
    int findLeftMostNode(TreeNode* root) {
        int val = 0, maxLevel = -1;
        if (root) myHelper(root, 0, maxLevel, val);
        return val;
    }

private:
    void myHelper(const TreeNode* node, const int level, int& maxLevel, int& val) {
        if (level > maxLevel) {
            maxLevel = level;
            val = node->val;
        }

        if (node->left) myHelper(node->left, level + 1, maxLevel, val);
        if (node->right) myHelper(node->right, level + 1, maxLevel, val);
    }
};
