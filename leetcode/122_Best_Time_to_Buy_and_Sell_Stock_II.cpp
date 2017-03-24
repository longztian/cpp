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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();

        int profit = 0;

        for (int i = 1; i < N; ++i) {
            profit += max(prices[i] - prices[i - 1], 0);
        }

        return profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        struct State {
            int buy;  // buy status and after
            int sel;  // sell status and after

            State() : buy(INT_MIN), sel(0) {};
        };

        array<State, 2> states;
        for (auto p : prices) {
            states[1].buy = max(states[1].buy, states[0].sel - p);
            states[1].sel = max(states[1].sel, states[0].buy + p);

            states[0] = states[1];
        }

        return states[1].sel;
    }
};
