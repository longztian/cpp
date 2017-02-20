class Solution {
public:
    int numSquares(int n) {
        std::vector<int> cache(n + 1, -1);
        cache[0] = 0;
        return myNumSquares(n, cache);
    }

private:
    int myNumSquares(int n, std::vector<int>& cache) {
        if (cache[n] == -1) {
            const int N = std::sqrt(n);

            int minN = n;
            for (int i = N; i > 0; --i) {
                minN = std::min(1 + myNumSquares(n - i * i, cache), minN);
            }

            cache[n] = minN;
        }

        return cache[n];
    }
};
