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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        myHead = head;
        myRand = head;
        myLength = 1;

        int nMax = min(std::numeric_limits<int>::max(), RAND_MAX);
        auto p = head->next;
        while (p != nullptr && p != head && myLength < nMax) {
            p = p->next;
            ++myLength;
        }


    }

    /** Returns a random node's value. */
    int getRandom() {
        int n = rand() % myLength;
        while (n--) {
            myRand = myRand->next != nullptr ? myRand->next : myHead;
        }

        return myRand->val;
    }

private:
    ListNode* myHead;
    ListNode* myRand;
    int myLength;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
