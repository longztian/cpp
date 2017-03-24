class Solution {
public:
    double myPow(double x, int n) {
        return myPow(x, static_cast<long>(n));
    }

private:
    double myPow(double x, long n) {
        if (n < 0) return 1 / myPow(x, n * -1);
        if (n == 0) return 1;
        if (n == 1) return x;

        double half = myPow(x, n / 2);
        return n % 2 == 0 ? half * half : half * half * x;
    }
};
