class Solution {
public:
    int integerReplacement(int n) {
        if (n <= 0) return 0;
        unordered_map<int, int> cache;
        return myIntReplace(n, cache);
    }

private:
    int myIntReplace(long n, unordered_map<int, int>& cache) {
        if (n == 1) return 0;

        auto it = cache.find(n);
        if (it == cache.end()) {
            int nSteps = 1;

            if (n % 2 == 0) {
                nSteps += myIntReplace(n / 2, cache);
            } else {
                nSteps += min(myIntReplace(n + 1, cache), myIntReplace(n - 1, cache));
            }

            it = cache.emplace(n, nSteps).first;
        }

        return it->second;
    }
};
