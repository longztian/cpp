class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;

        vector<int> mins(nums.size(), INT_MAX);
        int minv = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            if (minv > nums[i - 1]) minv = nums[i - 1];
            if (minv < nums[i] - 1) mins[i] = minv;
        }

        map<int, int> valueLast;
        for (int i = 0; i < nums.size(); ++i) {
            valueLast[nums[i]] = i;
        }

        for (int j = 1; j < nums.size() - 1; ++j) {
            if (mins[j] != INT_MAX) {
                auto itb = ++(valueLast.find(mins[j]));
                auto ite = valueLast.find(nums[j]);
                while (itb != ite) {
                    if ((itb)->second > j) return true;
                    ++itb;
                }
            }
        }

        return false;
    }
};
