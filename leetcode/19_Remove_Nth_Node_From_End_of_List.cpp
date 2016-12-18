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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return head;

        auto p = head;
        while(n && p) {
            p = p->next;
            --n;
        }

        auto dummy = new ListNode(0);
        dummy->next = head;

        auto q = dummy;
        while(p) {
            q = q->next;
            p = p->next;
        }

        p = q->next;
        q->next = p->next;
        delete p;

        p = dummy->next;
        delete dummy;

        return p;
    }
};
