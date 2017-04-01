class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.size();
        if (N < 2) return s;

        const auto PE = s.data() + s.size();

        size_t nMax = 1;
        auto pbMax = s.data(), peMax = pbMax + nMax;
        for (auto pb = s.data(); pb < PE - nMax; ++pb) {
            for (auto pe = pb + nMax + 1; pe <= PE; ++pe) {
                if (myIsPalindrome(pb, pe) && pe - pb > nMax) {
                    nMax = pe - pb;
                    pbMax = pb;
                    peMax = pe;
                }
            }
        }

        return string(pbMax, peMax);
    }

private:
    bool myIsPalindrome(const char* pb, const char* pe) {
        while (pb < pe - 1) {
            --pe;
            if (*pb != *pe) return false;
            ++pb;
        }
        return true;
    }
};
