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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        TreeNode* last = nullptr;
        return myInOrder(root, &last);
    }

private:
    bool myInOrder(TreeNode* root, TreeNode** last) {
        if (root->left && !myInOrder(root->left, last)) return false;
        if (*last && (*last)->val >= root->val) return false;
        *last = root;
        if (root->right && !myInOrder(root->right, last)) return false;
        return true;
    }
};
