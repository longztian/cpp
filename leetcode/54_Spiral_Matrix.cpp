class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int NR = matrix.size();
        if (NR == 0) return {};

        const int NC = matrix.front().size();
        if (NC == 0) return {};

        vector<int> ret;
        myOrder(matrix, ret, 0, NR, 0, NC);

        return ret;
    }

private:
    void myOrder(const vector<vector<int>>& matrix, vector<int>& ret,
                 size_t rb, size_t re, size_t cb, size_t ce) {
        --re;
        --ce;

        if (rb > re || cb > ce) return;

        if (rb == re) {
            for (int c = cb; c <= ce; ++c) {
                ret.push_back(matrix[rb][c]);
            }
            return;
        }
        if (cb == ce) {
            for (int r = rb; r <= re; ++r) {
                ret.push_back(matrix[r][cb]);
            }
            return;
        }

        auto r = rb, c = cb;
        while (c < ce) ret.push_back(matrix[r][c++]);
        while (r < re) ret.push_back(matrix[r++][c]);
        while (c > cb) ret.push_back(matrix[r][c--]);
        while (r > rb) ret.push_back(matrix[r--][c]);

        ++rb;
        ++cb;

        myOrder(matrix, ret, rb, re, cb, ce);
    }
};
