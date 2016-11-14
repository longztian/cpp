bool myComp(const pair<const int, int>& i, const pair<const int, int>& j) {
    return i.first < j.first;
}

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;

        vector<int> min_i(nums.size(), INT_MAX);
        int min = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            if (min > nums[i - 1]) min = nums[i - 1];
            if (min < nums[i]) min_i[i] = min;
        }

        map<int, int> valueLastIndex;
        for (int i = 0; i < nums.size(); ++i) {
            valueLastIndex[nums[i]] = i;
        }

        int i, j, k, max_k;
        for (j = 1; j < nums.size() - 1; ++j) {
            if (min_i[j] == INT_MAX) continue;

            auto itb = upper_bound(valueLastIndex.begin(), valueLastIndex.end(), pair<const int, int>({min_i[j], 0}), myComp);
            auto ite = lower_bound(valueLastIndex.begin(), valueLastIndex.end(), pair<const int, int>({nums[j], 0}), myComp);

            while (itb != ite) {
                if (itb->second > j) return true;
                ++itb;
            }
        }

        return false;
    }

};
