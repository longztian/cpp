using Key = pair<int, unordered_set<int>>;

namespace std {
template <> struct hash<Key> {
    size_t operator()(const Key& k) const {
        return hash<int>()(k.first);
    }
};
}

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) return true;
        if (desiredTotal == maxChoosableInteger + 1) return false;
        if (desiredTotal == maxChoosableInteger + 2) return true;

        unordered_set<int> nums;
        for (int i = 1; i <= maxChoosableInteger; ++i) nums.insert(i);

        return myDP(nums, desiredTotal, true);
    }

private:
    bool myDP(unordered_set<int>& nums, int total, bool myTurn) {
        if (total <= 0) return !myTurn;
        if (nums.find(total) != nums.end()) return myTurn;

        auto it = myWin.find({total, nums});
        if (it == myWin.end()) {
            bool win = false;
            for (int i : nums) {
                nums.erase(i);
                win = myDP(nums, total - i, !myTurn);
                nums.insert(i);
                if (win) break;
            }
            it = myWin.insert({make_pair(total, nums), win}).first;
        }

        return myTurn && it->second;
    }

    unordered_map<Key, bool> myWin;

};
