class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        if (N < 2) return false;

        // non-negative integers

        if (k == 0) {
            // find two continuous 0
            auto pb = nums.data(), pe = pb + nums.size() - 1;
            while (pb < pe) {
                if (*pb++ != 0) continue;
                if (*pb++ == 0) return true;
            }
            return false;
        }

        // prifix sum
        vector<long> sums(N + 1, 0);
        for (int i = 0; i < N; ++i) sums[i + 1] = sums[i] + nums[i];

        // s[j] - s[i] = n * k
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 2; j <= N; ++j) {
                if ((sums[j] - sums[i]) % k == 0) return true;
            }
        }

        return false;
    }
};
