class Solution {
public:
    string removeKdigits(string num, int k) {
        // corner cases
        if (k <= 0) return num.empty() ? "0" : num;

        const int N = num.size();
        if (N <= k) return "0";

        // can skip all digits before a '0'
        const auto PB = num.data(), PE = PB + N;
        auto p = PB;
        while (p < PE && *p != '0') ++p;
        const int n = p - PB;
        if (n <= k) {
            while (p < PE && *p == '0') ++p;
            return removeKdigits(string(p, PE), k - n);
        }

        // won't have leading zeros
        string ret;
        ret.reserve(N);
        ret.push_back(*PB);

        int skipped = 0;
        for (p = PB + 1; p < PE; ++p) {
            while (skipped < k && !ret.empty() && *p < ret.back()) {
                ret.pop_back();
                ++skipped;
            }

            ret.push_back(*p);
        }
        ret.resize(N - k);

        return ret;
    }
};
