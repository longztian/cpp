class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = numeric_limits<int>::max();
        long sum = 0;
        for (int v : nums) {
            if (min > v) min = v;
            sum += v;
        }

        return sum - min * nums.size();
    }
};
