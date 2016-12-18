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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) return nullptr;

        return myBuildTree(preorder.data(), inorder.data(), inorder.size());
    }

private:
    TreeNode* myBuildTree(const int* preB, const int* inB, const int n) {
        auto root = new TreeNode(*preB);

        if (n > 1) {
            auto pRoot = std::find(inB, inB + n, *preB);
            auto l = pRoot - inB, r = n - l  - 1;
            if (l) root->left = myBuildTree(preB + 1, inB, l);
            if (r) root->right = myBuildTree(preB + l + 1, inB + l + 1, r);
        }

        return root;
    }
};
