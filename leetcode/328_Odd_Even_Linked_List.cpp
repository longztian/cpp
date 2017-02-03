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
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummy(0), even(0), odd(0);
        auto p = &dummy, pe = &even, po = &odd;
        dummy.next = head;

        bool isOdd = true;
        while (p->next) {
            p = p->next;

            if (isOdd) {
                po->next = p;
                po = po->next;
            } else {
                pe->next = p;
                pe = pe->next;
            }

            isOdd = !isOdd;
        }
        po->next = even.next;
        pe->next = nullptr;

        return odd.next;
    }
};
