class Solution {
public:
    bool isPowerOfTwo(int n) {
        constexpr int max = pow(2, static_cast<int>(log2(numeric_limits<int>::max())));
        return n > 0 && max % n == 0;
    }
};
