// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n, m;
        while (i < j) {
            m = i + (j - i) / 2;
            switch (guess(m)) {
                case -1: j = m - 1; break;
                case 1: i = m + 1; break;
                default: return m;
            }
        }
        return i;
    }
};
