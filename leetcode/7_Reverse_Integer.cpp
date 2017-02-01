class Solution {
public:
    int reverse(int x) {
        long ret = 0;

        if (x > 0) {
            int max = numeric_limits<int>::max();
            while (x) {
                ret = ret * 10 + x % 10;
                x /= 10;
                if (ret > max) return 0;
            }
        }
        else {
            int min = numeric_limits<int>::min();
            while (x) {
                ret = ret * 10 + x % 10;
                x /= 10;
                if (ret < min) return 0;
            }
        }

        return static_cast<int>(ret);
    }
};
