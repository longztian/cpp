/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p, *dummy = new ListNode(0);

        while (head) {
            p = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = p;
        }

        p = dummy->next;
        delete dummy;

        return p;
    }
};
