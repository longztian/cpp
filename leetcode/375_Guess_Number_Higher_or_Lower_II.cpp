class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> cache(n + 1, vector<int>(n + 1, 0));
        return myDP(1, n, cache);
    }

private:
    int myDP(int i, int j, vector<vector<int>>& cache) {
        if (i >= j) return 0;
        if (cache[i][j] != 0) return cache[i][j];

        int minMax = numeric_limits<int>::max(), maxS;
        for (int x = i; x <= j; ++x) {
            maxS = x + max(myDP(i, x - 1, cache), myDP(x + 1, j, cache));
            minMax = min(minMax, maxS);
        }

        cache[i][j] = minMax;
        return minMax;
    }
};
