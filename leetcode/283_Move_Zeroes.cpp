class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto begin = nums.data(), end = begin + nums.size();

        auto p0 = begin;
        while (p0 < end && *p0 != 0) ++p0;

        for (auto p = p0 + 1; p < end; ++p) {
            if (*p == 0) continue;

            // move non-zero
            *p0 = *p;
            ++p0;
        }

        // fill zeros
        while (p0 < end) {
            *p0 = 0;
            ++p0;
        }
    }
};
