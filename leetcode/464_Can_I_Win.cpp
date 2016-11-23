class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 1 || desiredTotal <= maxChoosableInteger) return true;

        long sum = ((long) maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (desiredTotal > sum) return false;
        if (desiredTotal == sum) return maxChoosableInteger % 2 == 1;

        vector<bool> nums(maxChoosableInteger + 1, true);
        unordered_map<vector<bool>, bool> cache;

        return myDP(desiredTotal, nums, cache);
    }

private:
    bool myDP(int total, vector<bool>& nums, unordered_map<vector<bool>, bool>& cache) {
        auto it = cache.find(nums);
        if (it != cache.end()) return it->second;

        bool win = false;

        for (int i = total; !win && i < nums.size(); ++i) {
            if (nums[i]) win = true;
        }

        for (int i = 1, n = min((int) nums.size(), total); !win && i < n; ++i) {
            if (nums[i]) {
                nums[i] = false;
                win = !myDP(total - i, nums, cache); // win in current path, if next player would always lose
                nums[i] = true;
            }
        }

        cache[nums] = win;
        return win;
    }
};
