// O(n) space
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return vector<int>();

        vector<int> count(n + 1, 0);
        for (int i : nums) ++count[i];

        vector<int> miss;
        for (int i = 1; i <= n; ++i) {
            if (count[i] == 0) miss.push_back(i);
        }

        return miss;
    }
};

// O(1) space
// mark number by *= -1 (not = 0), so can change the existing values back
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return vector<int>();

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                int j = nums[i] - 1, tmp;
                while (nums[j] > 0) {
                    tmp = nums[j] - 1;
                    nums[j] *= -1;
                    j = tmp;
                }
            }
        }

        vector<int> miss;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) miss.push_back(i + 1);
        }

        return miss;
    }
};
