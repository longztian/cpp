class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return myHelper(nums, target);
    }

private:
    int myHelper(const vector<int>& nums, int target) {
        if (target <= 0) return 0;

        // get from cache
        auto it = myCache.find(target);
        if (it != myCache.end()) return it->second;

        // count
        auto i = nums.begin(), e = lower_bound(nums.begin(), nums.end(), target);
        int n = (e != nums.end() && *e == target ? 1 : 0);
        while (i != e) {
            n += myHelper(nums, target - *i);
            ++i;
        }

        // save to cache and return
        myCache[target] = n;
        return n;
    }

    unordered_map<int, int> myCache;
};

// Solution 2:
// there is a risk of int overflow
// need to change to long, or cast to size_t
class Solution {
public:
    long combinationSum4(vector<int>& nums, int target) {
        vector<long> dp((unsigned int) target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto v : nums) {
                if (i >= v) dp[i] += dp[i - v];
            }
        }

        return dp[target];
    }
};
