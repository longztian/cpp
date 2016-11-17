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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;

        while (head) {
            if (nodes.find(head) != nodes.end()) return true;
            nodes.insert(head);
            head = head->next;
        }

        return false;
    }
};

// slow-fast pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head) {
            auto fast = head, slow = head;

            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (fast == slow) return true;
            }
        }

        return false;
    }
};
