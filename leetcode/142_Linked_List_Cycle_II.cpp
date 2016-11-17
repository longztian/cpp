/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// cache all pointers and lookup
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;

        while (head) {
            if (nodes.find(head) != nodes.end()) return head;
            nodes.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};

// slow-fast pointers
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head) {
            bool hasCircle = false;
            auto fast = head, slow = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    hasCircle = true;
                    break;
                }
            }

            if (hasCircle) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }

                return fast;
            }
        }

        return nullptr;
    }
};
