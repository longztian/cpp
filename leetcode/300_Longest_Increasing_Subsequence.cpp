// O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        if (N < 2) return N;

        vector<int> counts(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) counts[i] = max(counts[i], counts[j] + 1);
            }
        }

        return *max_element(counts.begin(), counts.end());
    }
};


// O(Nlog(N))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        if (N < 2) return N;

        vector<int> tails;
        auto it = tails.end();
        for (auto v : nums) {
            it = lower_bound(tails.begin(), tails.end(), v);
            if (it == tails.end()) tails.push_back(v);
            else *it = v;
        }

        return tails.size();
    }
};
