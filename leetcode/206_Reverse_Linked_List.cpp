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
        ListNode dummy(0);
        ListNode* p;

        while (head) {
            p = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = p;
        }

        return dummy.next;
    }
};
