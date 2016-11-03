class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k <= 0 || k > 9 || n <= 0 || n > (9 + 1) * 9 / 2) return result;

        // k = [1,9], n = [1,45]
        vector<int> comb;
        myHelper(result, comb, n, k);
        return result;
    }

private:
    void myHelper(vector<vector<int>>& result, vector<int>& comb, int n, int k) {
        if (k == 0) {
            if (n == 0) result.push_back(comb);
            return;
        } else {
            int begin = comb.empty() ? 1 : comb.back() + 1;
            if (9 - begin + 1 < k) return;

            for (int i = begin; i <= 9 && i <= n; ++i) {
                comb.push_back(i);
                myHelper(result, comb, n - i, k - 1);
                comb.pop_back();
            }
        }
    }
};
