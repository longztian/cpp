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


// minimax
// only has two scores: true / false
using Cache = unordered_map<vector<bool>, bool>;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        long sum = ((long) maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (sum < desiredTotal) return false;

        Cache maxCache, minCache;
        vector<bool> state(maxChoosableInteger + 1, true);
        return myMiniMax(state, desiredTotal, true, maxCache, minCache);
    }

private:
    bool myMiniMax(vector<bool>& state, int total, bool isMaxPlayer, Cache& maxCache, Cache& minCache) {
        if (isMaxPlayer) {
            auto it = maxCache.find(state);
            if (it != maxCache.end()) return it->second;

            bool maxScore = false;
            for (int i = total; !maxScore && i < state.size(); ++i) {
                if (state[i]) maxScore = true;
            }

            for (int i = 1, n = min(total, (int) state.size()); !maxScore && i < n; ++i) {
                if (state[i]) {
                    state[i] = false;
                    maxScore = myMiniMax(state, total - i, !isMaxPlayer, maxCache, minCache);
                    state[i] = true;
                }
            }

            maxCache[state] = maxScore;
            return maxScore;
        } else {
            auto it = minCache.find(state);
            if (it != minCache.end()) return it->second;

            bool minScore = true;
            for (int i = total; minScore && i < state.size(); ++i) {
                if (state[i]) minScore = false;
            }

            for (int i = 1, n = min(total, (int) state.size()); minScore && i < n; ++i) {
                if (state[i]) {
                    state[i] = false;
                    minScore = myMiniMax(state, total - i, !isMaxPlayer, maxCache, minCache);
                    state[i] = true;
                }
            }

            minCache[state] = minScore;
            return minScore;
        }
    }
};
