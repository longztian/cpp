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
    void flatten(TreeNode* root) {
        if (root) {
            if (root->left) flatten(root->left);
            if (root->right) flatten(root->right);

            if (root->left) {
                if (root->right) {
                    TreeNode* p = root->left;
                    while (p->right) p = p->right;
                    p->right = root->right;
                }

                root->right = root->left;
                root->left = nullptr;
            }
        }
    }
};
