class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size();
        if (N < 3) return 0;

        int minA = A.front(), maxA = A.front();
        for (int v : A) {
            if (minA > v) {
                minA = v;
            } else if (maxA < v) {
                maxA = v;
            }
        }
        long maxStep = ((long) maxA - minA + 1) / 2;

        unordered_map<int, Sequence> stepSeqs;
        long step;
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                step = (long) A[j] - A[i];
                if (step > maxStep || step < maxStep * -1) continue;
                stepSeqs[step].ij[i].push_back(j);
            }
        }

        int n = 0;
        for (auto it = stepSeqs.begin();  it != stepSeqs.end(); ++it) {
            n += it->second.count();
        }

        return n;
    }

private:
    class Sequence {
    public:
        unordered_map<int, vector<int>> ij;

        int count() {
            if (ij.size() < 2) return 0;

            int n = 0;
            vector<int> cache(1000, 0);
            for (auto it = ij.begin(); it != ij.end(); ++it) {
                n += (myCountSeqs(it->first, cache) - 1 - it->second.size());
            }

            return n;
        }
    private:
        int myCountSeqs(const int i, vector<int>& cache) {
            if (cache[i] > 0) return cache[i];

            int n = 1;

            auto it = ij.find(i);
            if (it != ij.end()) {
                for (int j : it->second) {
                    n += myCountSeqs(j, cache);
                }
            }

            cache[i] = n;
            return n;
        }
    };
};
