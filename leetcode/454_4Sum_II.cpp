class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        const int N = A.size();
        if (N == 0) return 0;

        unordered_map<int, int> abSum, cdSum;
        for (int i : A) {
            for (int j : B) {
                abSum[i + j] += 1;
            }
        }

        for (int i : C) {
            for (int j : D) {
                cdSum[i + j] += 1;
            }
        }

        int n = 0;
        for (auto& ab : abSum) {
            auto it = cdSum.find(0 - ab.first);
            if (it != cdSum.end()) n += ab.second * it->second;
        }

        return n;
    }
};
