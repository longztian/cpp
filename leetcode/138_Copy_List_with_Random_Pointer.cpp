/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;

        unordered_map<RandomListNode*, RandomListNode*> pointerMap;

        RandomListNode dummyOld(0), dummyNew(0);
        dummyOld.next = head;



        for (auto pOld = &dummyOld, pNew = &dummyNew; pOld->next; pOld = pOld->next, pNew = pNew->next) {
            pNew->next = new RandomListNode(pOld->next->label);
            pointerMap.emplace(pOld->next, pNew->next);
        }

        for (auto pOld = &dummyOld, pNew = &dummyNew; pOld->next; pOld = pOld->next, pNew = pNew->next) {
            pNew->next->random = pointerMap[pOld->next->random];
        }

        return dummyNew.next;
    }
};
