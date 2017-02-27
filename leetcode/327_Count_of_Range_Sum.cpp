class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int N = nums.size();
        vector<long> sums(N + 1, 0);

        for (int i = 0; i < N; ++i) sums[i + 1] = sums[i] + nums[i];

        int count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N + 1; ++j) {
                if (sums[j] - sums[i] >= lower && sums[j] - sums[i] <= upper) ++count;
            }
        }

        return count;
    }
};

// compare two element
// use ordered container to cache element from one side

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const auto N = nums.size();
        auto sums = vector<long>(N + 1, 0l);

        for (auto i = 0u; i < N; ++i) sums[i + 1] = sums[i] + nums[i];

        auto ordered = vector<long>();
        ordered.reserve(N + 1);

        // s[j] - s[i] = s[i..j-1] <= upper
        // s[j] - s[i] = s[i..j-1] >= lower
        // range in ordered elements:
        //    s[j] >= s[i] + lower
        //    s[j] <= s[i] + upper
        auto count = 0;
        for (auto it = sums.rbegin(), ite = sums.rend(); it != ite; ++it) {
            count += std::distance(std::lower_bound(ordered.begin(), ordered.end(), *it + lower),
                                   std::upper_bound(ordered.begin(), ordered.end(), *it + upper));
            ordered.insert(std::upper_bound(ordered.begin(), ordered.end(), *it), *it);
        }

        return count;
    }
};
