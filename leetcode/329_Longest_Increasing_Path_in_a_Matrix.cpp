const vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int NR = matrix.size();
        if (NR == 0) return 0;
        const int NC = matrix.front().size();
        if (NC == 0) return 0;

        vector<vector<int>> cache(NR, vector<int>(NC, -1));
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                myMaxPathLength(i, j, NR, NC, matrix, cache);
            }
        }

        int maxLen = 0;
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                maxLen = std::max(maxLen, cache[i][j]);
            }
        }
        return maxLen;
    }

private:
    void myMaxPathLength(const int r, const int c, const int NR, const int NC,
                        const vector<vector<int>>& m, vector<vector<int>>& cache) {
        if (cache[r][c] != -1) return;

        int maxLen = 1, i, j;
        for (const auto& d : dir) {
            i = r + d.first;
            j = c + d.second;

            if (i < 0 || j < 0 || i == NR || j == NC) continue;

            if (m[r][c] < m[i][j]) {
                myMaxPathLength(i, j, NR, NC, m, cache);
                maxLen = std::max(maxLen, cache[i][j] + 1);
            }
        }

        cache[r][c] = maxLen;
    }
};
