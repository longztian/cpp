class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) return 0;
        return myFindTargetSumWays(nums.data(), nums.data() + nums.size(), S);
    }

private:
    int myFindTargetSumWays(const int* PB, const int* PE, const int S) const {
        if (PB == PE - 1) {
            if (abs(*PB) != abs(S)) return 0;
            else return S == 0 ? 2 : 1;
        }

        int nMinus = myFindTargetSumWays(PB + 1, PE, S - *PB);
        int nPlus = myFindTargetSumWays(PB + 1, PE, S + *PB);

        return (nMinus ? nMinus : 0) + (nPlus ? nPlus : 0);
    }
};
