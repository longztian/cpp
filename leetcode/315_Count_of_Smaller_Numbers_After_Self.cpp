class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ordered;
        ordered.reserve(nums.size());

        vector<int> ret(nums.size(), 0);

        auto itc = ret.rbegin();
        vector<int>::iterator ito;
        for (auto it = nums.crbegin(), ite = nums.crend(); it != ite; ++it, ++itc) {
            ito = std::lower_bound(ordered.begin(), ordered.end(), *it);
            *itc = std::distance(ordered.begin(), ito);
            ordered.insert(ito, *it);
        }

        return ret;
    }
};
