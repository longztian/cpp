class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n <= 0 || k <= 0 || k > n) return result;

        // n >= 1, k >= 1, k <= n
        vector<int> comb;
        myHelper(result, comb, 1, n, k);
        return result;
    }

private:
    void myHelper(vector<vector<int>>& result, vector<int>& comb, const int begin, const int end, const int k) {
        if (comb.size() == k) {
            result.push_back(comb);
        } else {
            if (comb.size() + end - begin + 1 == k) {
                result.push_back(comb);
                for (int i = begin; i <= end; ++i) result.back().push_back(i);
            } else if (comb.size() + end - begin + 1 > k) {
                for (int i = begin; i <= end; ++i) {
                    comb.push_back(i);
                    myHelper(result, comb, i + 1, end, k);
                    comb.pop_back();
                }
            }
        }
    }
};
