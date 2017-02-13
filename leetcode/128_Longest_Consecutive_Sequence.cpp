class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_map<int, ListNode> nodes;
        for (int i : nums) nodes.emplace(i, ListNode());

        // build linked lists
        auto ite = nodes.end(), itn = ite;
        for (auto it = nodes.begin(); it != ite; ++it) {
            itn = nodes.find(it->first + 1);
            if (itn != ite) {
                it->second.next = &itn->second;
                itn->second.prev = &it->second;
            }
        }

        // find list heads
        std::vector<ListNode*> heads;
        for (auto& v : nodes) {
            if (v.second.prev == nullptr) heads.push_back(&v.second);
        }

        // find max length
        int n = 1, maxN = 1;
        for (auto h : heads) {
            n = myCount(h);
            if (n > maxN) maxN = n;
        }

        return maxN;
    }

private:
    struct ListNode {
        ListNode* prev;
        ListNode* next;

        ListNode() : prev(nullptr), next(nullptr) {};
    };

    int myCount(ListNode* head) {
        int n = 1;

        while (head->next) {
            ++n;
            head = head->next;
        }

        return n;
    }
};
