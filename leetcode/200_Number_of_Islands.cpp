class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int r = grid.size();
        if (r == 0) return 0;
        const int c = grid[0].size();
        if (c == 0) return 0;

        int n = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                n += myTraverseIsland(grid, i, j, r, c);
            }
        }

        return n;
    }

private:
    int myTraverseIsland(vector<vector<char>>& grid, const int i, const int j, const int r, const int c) {
        if (i < 0 || j < 0 || i >= r || j >= c) return 0;
        if (grid[i][j] == '0') return 0;

        // mark as visited
        grid[i][j] = '0';
        // traverse 4 adjacent neighbors
        myTraverseIsland(grid, i - 1, j, r, c);
        myTraverseIsland(grid, i, j - 1, r, c);
        myTraverseIsland(grid, i, j + 1, r, c);
        myTraverseIsland(grid, i + 1, j, r, c);

        return 1;
    }
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        const int nr = grid.size();
        const int nc = grid.front().size();

        int n = 0;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                if (grid[i][j] == '1') {
                    ++n;
                    myMarkIslands(grid, i, j, nr, nc);
                }
            }
        }

        return n;
    }

private:
    void myMarkIslands(vector<vector<char>>& grid, int i, int j, const int nr, const int nc) {
        if (i < 0 || j < 0 || i >= nr || j >= nc || grid[i][j] == '0') return;

        grid[i][j] = '0';
        myMarkIslands(grid, i - 1, j, nr, nc);
        myMarkIslands(grid, i + 1, j, nr, nc);
        myMarkIslands(grid, i, j - 1, nr, nc);
        myMarkIslands(grid, i, j + 1, nr, nc);
    }
};
