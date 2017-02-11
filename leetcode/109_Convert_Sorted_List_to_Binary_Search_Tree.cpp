/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;

        vector<int> values;
        myListToVector(head, values);

        return myVectorToBst(values.data(), values.data() + values.size() - 1);
    }

private:
    void myListToVector(ListNode* head, vector<int>& values) {
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* myVectorToBst(int* begin, int* end) {
        if (begin == end) return new TreeNode(*begin);

        auto p = begin + (end - begin) / 2;
        auto root = new TreeNode(*p);
        if (p > begin) root->left = myVectorToBst(begin, p - 1);
        if (p < end) root->right = myVectorToBst(p + 1, end);

        return root;
    }
};
