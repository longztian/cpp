class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::unordered_set<int> rows, columns;

        const int NR = matrix.size();
        if (NR == 0) return;

        const int NC = matrix.front().size();
        if (NC == 0) return;

        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }

        for (auto i : rows) {
            for (int j = 0; j < NC; ++j) matrix[i][j] = 0;
        }

        for (int i = 0; i < NR; ++i) {
            for (auto j : columns) matrix[i][j] = 0;
        }
    }
};
