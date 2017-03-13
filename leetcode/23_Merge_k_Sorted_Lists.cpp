/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

namespace std {
template <> struct less<ListNode*> {
    bool operator()(const ListNode* lhs, const ListNode* rhs) const {
        return lhs->val > rhs->val;
    }
};
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*> q;

        for (auto p : lists) if (p) q.push(p);
        ListNode dummy(0);
        auto p = &dummy;
        while(!q.empty()) {
            p->next = q.top();
            q.pop();

            p = p->next;

            if (p->next) q.push(p->next);
        }

        return dummy.next;
    }
};
