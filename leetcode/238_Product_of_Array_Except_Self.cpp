class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        // left side
        int lp = 1;
        result[0] = lp;
        for (int i = 0; i < n - 1; ++i) {
            lp *= nums[i];
            result[i + 1] = lp;
        }

        // right side
        int rp = 1;
        for (int i = n - 1; i > 0; --i) {
            rp *= nums[i];
            result[i - 1] *= rp;
        }

        return result;
    }
};
