class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ret;

        const int NR = matrix.size();
        if (NR == 0) return ret;
        const int NC = matrix.front().size();
        if (NC == 0) return ret;

        vector<vector<int>> toPac(NR, vector<int>(NC, 0)), toAtl(NR, vector<int>(NC, 0));
        for (int j = 0; j < NC; ++j) {
            myDfs(0, j, INT_MIN, NR, NC, matrix, toPac);
            myDfs(NR - 1, j, INT_MIN, NR, NC, matrix, toAtl);
        }
        for (int i = 0; i < NR; ++i) {
            myDfs(i, 0, INT_MIN, NR, NC, matrix, toPac);
            myDfs(i, NC - 1, INT_MIN, NR, NC, matrix, toAtl);
        }

        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                if (toPac[i][j] == 1 && toAtl[i][j] == 1) ret.emplace_back(i, j);
            }
        }

        return ret;
    }

private:
    void myDfs(int i, int j, int height, int NR, int NC, const vector<vector<int>>& m, vector<vector<int>>& visited) {
        if (i < 0 || i >= NR || j < 0 || j >= NC || height > m[i][j] || visited[i][j] == 1) return;

        visited[i][j] = 1;
        myDfs(i - 1, j, m[i][j], NR, NC, m, visited);
        myDfs(i + 1, j, m[i][j], NR, NC, m, visited);
        myDfs(i, j - 1, m[i][j], NR, NC, m, visited);
        myDfs(i, j + 1, m[i][j], NR, NC, m, visited);
    }
};
