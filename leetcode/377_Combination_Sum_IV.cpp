/**
 * solution space is a tree with N children
 * O(N^(target / min(nums)))
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> myCache;

        return myHelper(nums, target, myCache);
    }

private:
    int myHelper(const vector<int>& nums, int target, unordered_map<int, int>& myCache) {
        if (target <= 0) return 0;

        // get from cache
        auto it = myCache.find(target);
        if (it != myCache.end()) return it->second;

        // count
        auto i = nums.begin(), e = lower_bound(nums.begin(), nums.end(), target);
        int n = (e != nums.end() && *e == target ? 1 : 0);
        while (i != e) {
            n += myHelper(nums, target - *i, myCache);
            ++i;
        }

        // save to cache and return
        myCache[target] = n;
        return n;
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> myCache(target + 1, -1);

        return myCount(nums, target, myCache);
    }

private:
    int myCount(const vector<int>& nums, int target, vector<int>& myCache) {
        if (myCache[target] != -1) return myCache[target];

        int count = 0;
        auto i = nums.begin(), e = nums.end();
        for (; i != e && *i < target; ++i) {
            count += myCount(nums, target - *i, myCache);
        }
        if (i != e && *i == target) ++count;

        myCache[target] = count;
        return count;
    }
};



// Solution 2:
// O(N * target)
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
