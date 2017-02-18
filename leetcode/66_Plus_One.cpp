class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto ret = digits;
        std::reverse(ret.begin(), ret.end());

        auto hasOne = true;
        for (int i = 0, n = digits.size(); hasOne && i < n; ++i) {
            if (ret[i] < 9) {
                ++ret[i];
                hasOne = false;
            }
            else {
                ret[i] = 0;
                hasOne = true;
            }
        }

        if (hasOne) ret.push_back(1);

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
