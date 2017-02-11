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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        return isBalanced(root->left)
            && isBalanced(root->right)
            && abs(myHeight(root->left) - myHeight(root->right)) < 2;
    }

private:
    unordered_map<TreeNode*, int> myHeights;

    int myHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        auto it = myHeights.find(root);

        if (it == myHeights.end()) {
            it = myHeights.emplace(root, max(myHeight(root->left), myHeight(root->right)) + 1).first;
        }

        return it->second;
    }
};
