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
        while (n && p) {
            p = p->next;
            --n;
        }

        if (n) return head;

        ListNode dummy(0);
        dummy.next = head;

        auto q = &dummy;
        while (p) {
            p = p->next;
            q = q->next;
        }

        p = q->next;
        q->next = p->next;
        delete p;

        return dummy.next;
    }
};
