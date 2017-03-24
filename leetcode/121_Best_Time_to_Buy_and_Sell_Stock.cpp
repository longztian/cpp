class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        * f(i) = max( f(i-1), a[i]-min(a[0]~a[i-1]) )
        * f(1) = a[1]-a[0]
        * f(2) = max( f(1), a[2]-min(a[0],a[1]) )
        *
        * f(i) = a[i] <= a[i-1] ? f(i-1)
        *                       : max( f(i-1), a[i]-min(a[0]~a[i-1]) )
        */
        if( prices.size() < 2 ) return 0;
        //if( prices.size() == 2 ) return prices[0] < prices[1] : prices[1] - prices[0] : 0;

        int min = prices[0], mp = 0;
        for( auto p = prices.data() + 1, e = prices.data() + prices.size(); p < e; ++p )
        {
            if( *p > *(p-1) && mp < (*p - min) )
            {
                mp = *p - min;
            }

            if( *p < min ) min = *p;
        }

        return mp;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();

        if (N < 2) return 0;

        int buy = prices[0], maxProfit = 0;
        for (int i = 1; i < N; ++i) {
            if (prices[i] <= buy) buy = prices[i];
            else maxProfit = max(maxProfit, prices[i] - buy);
        }

        return maxProfit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = numeric_limits<int>::max(), maxProfit = 0;

        for (auto p : prices) {
            if (p <= buy) buy = p;
            else maxProfit = max(maxProfit, p - buy);
        }

        return maxProfit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // balances at each state
        int buy = INT_MIN, sel = 0;

        for (auto p : prices) {
            buy = max(buy, 0 - p);
            sel = max(sel, buy + p);
        }

        return sel;
    }
};
