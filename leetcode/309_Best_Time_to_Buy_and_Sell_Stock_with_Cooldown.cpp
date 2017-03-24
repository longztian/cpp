class Solution {
public:
    int maxProfit(vector<int>& prices) {
        struct State {
            int buy;  // buy status and after
            int sell; // sell status and after
            int rest; // rest status and after
        };

        array<State, 2> states;
        states[0].buy = INT_MIN;
        states[0].sell = 0;
        states[0].rest = 0;

        for (auto p : prices) {
            states[1].buy = max(states[0].rest - p, states[0].buy);
            states[1].sell = max(states[0].buy + p, states[0].sell);
            states[1].rest = max(states[0].sell, states[0].rest);

            swap(states[0], states[1]);
        }

        return max(states[0].sell, states[0].rest);
    }
};
