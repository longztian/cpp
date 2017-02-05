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
    bool myInOrder(TreeNode* pRoot, TreeNode** ppLast) {
        if (pRoot->left && !myInOrder(pRoot->left, ppLast)) return false;

        if (*ppLast && (*ppLast)->val >= pRoot->val) return false;
        *ppLast = pRoot;

        if (pRoot->right && !myInOrder(pRoot->right, ppLast)) return false;

        return true;
    }
};
