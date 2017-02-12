class Solution {
public:
    int reversePairs(vector<int>& nums) {
        std::vector<long> ordered;
        ordered.reserve(nums.size());

        int n = 0, i = nums.size();
        long val = 0;

        while (i) {
            val = static_cast<long>(nums[--i]);
            n += std::distance(ordered.cbegin(), std::lower_bound(ordered.cbegin(), ordered.cend(), val));
            ordered.insert(std::upper_bound(ordered.begin(), ordered.end(), val * 2), val * 2);
        }

        return n;
    }
};
