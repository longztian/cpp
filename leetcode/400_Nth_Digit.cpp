class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;

        // 9 * 1 + 9 * 10 * 2 + 9 * 100 * 3 + ...
        long count = 9;  // int32 is easy to overflow here
        int len = 1;
        while (n >= count * len) {
            n -= count * len;
            count *= 10;
            ++len;
        }

        if (n == 0) return 9;

        int iDigit = n % len;
        int number = n / len - 1;

        if (iDigit == 0) return number % 10;

        number = count / 9 + number + 1;

        for (int i = 0; i < len - iDigit; ++i) number /= 10;
        return number % 10;
    }
};
