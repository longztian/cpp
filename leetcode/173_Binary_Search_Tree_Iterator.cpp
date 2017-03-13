/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root) {
            myStack.push(root);
            while (myStack.top()->left) myStack.push(myStack.top()->left);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto p = myStack.top();
        int v = p->val;
        myStack.pop();

        if (p->right) {
            myStack.push(p->right);
            while (myStack.top()->left) myStack.push(myStack.top()->left);
        }

        return v;
    }

private:
    stack<TreeNode*> myStack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
