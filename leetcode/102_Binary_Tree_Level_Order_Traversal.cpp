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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        myDfs(root, 0, ret);

        return ret;
    }

private:
    void myDfs(const TreeNode* root, int level, vector<vector<int>>& ret) {
        if (root == nullptr) return;

        if (ret.size() < level + 1)  ret.emplace_back();

        ret[level].push_back(root->val);

        level += 1;
        myDfs(root->left, level, ret);
        myDfs(root->right, level, ret);
    }
};
