class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int nr = grid.size();
        if (nr == 0) return 0;
        const int nc = grid[0].size();
        if (nc == 0) return 0;

        int n = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == 1) {
                    if (r > 0) n += grid[r - 1][c] == 0 ? 1 : 0;
                    else n += 1;

                    if (c > 0) n += grid[r][c - 1] == 0 ? 1 : 0;
                    else n += 1;

                    if (r < nr - 1) n += grid[r + 1][c] == 0 ? 1 : 0;
                    else n += 1;

                    if (c < nc - 1) n += grid[r][c + 1] == 0 ? 1 : 0;
                    else n += 1;
                }
            }
        }

        return n;
    }
};



const vector<pair<int, int>> dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int NR = grid.size();
        if (NR == 0) return 0;
        const int NC = grid.front().size();
        if (NC == 0) return 0;

        int perimeter = 0, x, y;
        for (int i = 0; i < NR; ++i) {
            for (int j = 0; j < NC; ++j) {
                if (grid[i][j] == 0) continue;

                for (const auto& d : dir) {
                    x = i + d.first;
                    y = j + d.second;
                    if (x < 0 || x == NR || y < 0 || y == NC || grid[x][y] == 0) ++perimeter;
                }
            }
        }

        return perimeter;
    }
};
