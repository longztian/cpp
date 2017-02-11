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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;

        myDfs(root, 0, ret);
        reverse(ret.begin(), ret.end());

        return ret;
    }

private:
    void myDfs(const TreeNode* root, const int level, vector<vector<int>>& ret) {
        if (root == nullptr) return;

        if (ret.size() <= level) ret.emplace_back();

        ret[level].push_back(root->val);
        myDfs(root->left, level + 1, ret);
        myDfs(root->right, level + 1, ret);
    }
};
