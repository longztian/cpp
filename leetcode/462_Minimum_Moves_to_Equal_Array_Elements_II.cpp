class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());

        long sum = 0;
        for (int i = 0, j = nums.size() - 1; i < nums.size() / 2; ++i, --j) {
            sum += ((long) nums[j] - nums[i]);
        }

        return sum;
    }
};


// quickselet to find median value
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int m = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        int v = nums[m];

        long sum = 0;
        auto p = nums.data(), e = p + m;
        for (int i = 0; i < m; ++i) sum += v - nums[i];
        for (int i = m + 1; i < nums.size(); ++i) sum += nums[i] - v;

        return sum;
    }
};
