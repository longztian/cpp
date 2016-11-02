class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the begin of the last reverse-ordered block
        int n = nums.size();
        int i = n - 1;
        while (i > 0 && nums[i-1] >= nums[i]) --i;

        if (i == 0) {
            // the whole array is reverse ordered
            reverse(nums.data(), nums.data() + n);
        } else {
            // reverse the last reverse-ordered block
            reverse(nums.data() + i, nums.data() + n);
            // swap nums[i-1] with its upper_bound value in the sorted block
            for (int j = i; j < n; ++j) {
                if (nums[j] > nums[i-1]) {
                    swap(nums[i-1], nums[j]);
                    break;
                }
            }
        }
    }
};