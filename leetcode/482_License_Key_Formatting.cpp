class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        const int N = S.size() - std::count(S.cbegin(), S.cend(), '-');
        if (N == 0) return std::string();

        const int N_FIRST = N % K;
        const int N_DASH = N_FIRST ? N / K : N / K - 1;

        string ret(N + N_DASH, '-');

        auto pIn = S.data();
        auto pOut = const_cast<char*>(ret.data());
        const std::locale loc;
        int n = 0;

        // first group
        if (N_FIRST) {
            n = N_FIRST;
            while (n) {
                if (*pIn != '-') {
                    *pOut = std::toupper(*pIn, loc);
                    ++pOut;
                    --n;
                }
                ++pIn;
            }

            ++pOut; // skip dash
        }

        // groups with K elements
        int ng = N / K + 1;
        while (--ng) {
            n = K;
            while (n) {
                if (*pIn != '-') {
                    *pOut = std::toupper(*pIn, loc);
                    ++pOut;
                    --n;
                }
                ++pIn;
            }

            ++pOut; // skip dash
        }

        return ret;
    }
};
