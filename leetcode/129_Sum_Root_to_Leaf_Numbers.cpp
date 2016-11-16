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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum = 0;
        vector<int> path;
        myPreOrder(root, path, sum);

        return sum;
    }

private:
    void myPreOrder(TreeNode* root, vector<int>& path, int& sum) {
        path.push_back(root->val);

        if (root->left) myPreOrder(root->left, path, sum);
        if (root->right) myPreOrder(root->right, path, sum);

        if (root->left == nullptr && root->right == nullptr) {
            int e = 1;
            for (auto it = path.crbegin(); it != path.crend(); ++it) {
                sum += *it * e;
                e *= 10;
            }
        }

        path.pop_back();
    }
};
