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


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const auto PB = nums.data(), PE = PB + nums.size();

        auto pZero = find(PB, PE, 0);
        auto pValue = find_if(pZero + 1, PE, [](int v) { return v != 0; });

        while (pValue < PE) {
            *pZero++ = *pValue++;
            pValue = find_if(pValue, PE, [](int v) { return v != 0; });
        }

        if (pZero < PE) fill(pZero, PE, 0);
    }
};
