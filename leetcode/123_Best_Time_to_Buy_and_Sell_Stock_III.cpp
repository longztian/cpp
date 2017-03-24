class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // balances
        int buy1 = INT_MIN, sel1 = 0, buy2 = INT_MIN, sel2 = 0;

        for (int p : prices) {
            buy1 = max(buy1, 0 - p);
            sel1 = max(sel1, buy1 + p);
            buy2 = max(buy2, sel1 - p);
            sel2 = max(sel2, buy2 + p);
        }

        return sel2;
    }
};
