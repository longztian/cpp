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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return myHelper(root->left, root->right);
    }

private:
    bool myHelper(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;

        return left->val == right->val
            && myHelper(left->left, right->right)
            && myHelper(left->right, right->left);
    }
};


/**
 * iterative solution
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        vector<TreeNode*> sl, sr;

        sl.push_back(root->left);
        sr.push_back(root->right);

        TreeNode *pl = nullptr, *pr = nullptr;

        while (!sl.empty()) {
            pl = sl.back();
            pr = sr.back();
            sl.pop_back();
            sr.pop_back();

            if (pl == nullptr && pr == nullptr) continue;
            if (pl == nullptr || pr == nullptr) return false;
            if (pl->val != pr->val) return false;

            sl.push_back(pl->right);
            sl.push_back(pl->left);
            sr.push_back(pr->left);
            sr.push_back(pr->right);
        }

        return true;
    }
};
