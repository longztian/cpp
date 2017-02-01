#include <algorithm>
#include <functional>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k -= 1;
        std::nth_element(nums.begin(), nums.begin() + k, nums.end(), std::greater<int>());
        return nums[k];
    }
};
