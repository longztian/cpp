/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * recursive solution
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root) myHelper(root, ret);
        return ret;
    }
private:
    void myHelper(TreeNode* root, vector<int>& ret) {
        ret.push_back(root->val);
        if (root->left) myHelper(root->left, ret);
        if (root->right) myHelper(root->right, ret);
    }
};

/**
 * iterative solution
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;

        vector<TreeNode*> stack;
        if (root) stack.push_back(root);

        TreeNode* p = nullptr;
        while (!stack.empty()) {
            p = stack.back();
            stack.pop_back();

            ret.push_back(p->val);

            if (p->right) stack.push_back(p->right);
            if (p->left) stack.push_back(p->left);
        }

        return ret;
    }
};
