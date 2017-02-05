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
        if (m == n) return head;
        n = n - m + 1;

        ListNode dummy(0);
        dummy.next = head;

        auto pE = &dummy;
        while (--m) pE = pE->next;

        ListNode dummyR(0);
        auto pRE = pE->next, p = pRE->next;
        dummyR.next = pRE;

        ListNode* pNext = nullptr;
        while (--n) {
            pNext = p->next;

            p->next = dummyR.next;
            dummyR.next = p;

            p = pNext;
        }

        pE->next = dummyR.next;
        pRE->next = p;

        return dummy.next;
    }
};
