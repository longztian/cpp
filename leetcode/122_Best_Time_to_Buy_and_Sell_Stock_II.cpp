class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        if (N < 2) return 0;

        // accumulate all positive changes
        int profit = 0, diff;
        for(int i = 1; i < N; ++i) {
            if (prices[i] > prices[i - 1]) profit += (prices[i] - prices[i - 1]);
        }

        return profit;
    }
};
