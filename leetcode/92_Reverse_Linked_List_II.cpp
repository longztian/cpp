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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p, *pEnd1, *pEnd2, *dummy0 = new ListNode(0), *dummy = new ListNode(0);

        dummy0->next = head;
        head = dummy0;

        for (int i = 1; i < m; ++i) {
            head = head->next;
        }

        pEnd1 = head;
        pEnd2 = head->next;

        head = head->next;

        for (int i = m; i <= n; ++i) {
            p = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = p;
        }

        pEnd1->next = dummy->next;
        if (head) pEnd2->next = head;
        p = dummy0->next;

        delete dummy0;
        delete dummy;

        return p;
    }
};
