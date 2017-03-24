class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();
        if (k > N / 2) k = N / 2;

        vector<int> buy(k, INT_MIN), sel(k + 1, 0);

        for (auto p : prices) {
            for (int i = 0; i < k; ++i) {
                buy[i] = max(buy[i], sel[i] - p);
                sel[i + 1] = max(sel[i + 1], buy[i] + p);
            }
        }

        return sel.back();
    }
};
