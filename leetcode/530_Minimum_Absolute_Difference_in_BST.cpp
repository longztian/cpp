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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr
            || root->left == nullptr && root->right == nullptr) return 0;


        stack<TreeNode*> s;
        s.push(root);
        while (s.top()->left) s.push(s.top()->left);

        int minD = INT_MAX;

        TreeNode *p = nullptr, *pl = nullptr;
        while (!s.empty()) {
            p = s.top();
            s.pop();

            if (pl) minD = min(minD, p->val - pl->val);
            pl = p;

            if (p->right) {
                s.push(p->right);
                while (s.top()->left) s.push(s.top()->left);
            }
        }

        return minD;
    }
};
