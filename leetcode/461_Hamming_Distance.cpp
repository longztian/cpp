class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, val = x ^ y;
        while (val) {
            dist += val & 1;
            val >>= 1;
        }

        return dist;
    }
};
