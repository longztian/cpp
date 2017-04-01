class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num < 2) return false;
        const int N = static_cast<int>(sqrt(num)) + 1;

        long sum = 1;
        for (int i = 2; i < N; ++i) {
            if (num % i == 0) {
                sum += i;
                sum += (num / i);
            }
        }

        return sum == num;
    }
};
