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
