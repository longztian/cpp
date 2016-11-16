/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct SumTreeNode {
    int val;
    int maxLeft;
    int maxRight;
    SumTreeNode *left;
    SumTreeNode *right;

    SumTreeNode(int v) : val(v), maxLeft(0), maxRight(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;

        SumTreeNode* sumRoot;
        myBuildSumTree(root, &sumRoot);

        return myGetMaxSum(sumRoot);
    }

private:
    void myBuildSumTree(TreeNode* root, SumTreeNode** pSumRoot) {
        *pSumRoot = new SumTreeNode(root->val);
        auto& node = **pSumRoot;

        int maxChild;
        if (root->left) {
            myBuildSumTree(root->left, &node.left);
            maxChild = max(node.left->maxLeft, node.left->maxRight);
            node.maxLeft = maxChild > 0 ? maxChild + node.left->val : node.left->val;
        }

        if (root->right) {
            myBuildSumTree(root->right, &node.right);
            maxChild = max(node.right->maxLeft, node.right->maxRight);
            node.maxRight = maxChild > 0 ? maxChild + node.right->val : node.right->val;
        }
    }

    int myGetMaxSum(SumTreeNode* root) {
        int maxSum = root->val;
        maxSum = max(maxSum, maxSum + root->maxLeft);
        maxSum = max(maxSum, maxSum + root->maxRight);

        if (root->left) {
            int maxLeft = myGetMaxSum(root->left);
            maxSum = max(maxSum, maxLeft);
        }

        if (root->right) {
            int maxRight = myGetMaxSum(root->right);
            maxSum = max(maxSum, maxRight);
        }

        return maxSum;
    }
};
