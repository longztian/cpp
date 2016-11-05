class Solution {
public:
    using Grid = vector<vector<int>>;
    using Positions = vector<pair<int, int>>;

    vector<int> numIslands2(int m, int n, Positions& positions) {
        Grid grid(m, vector<int>(n, -1));
        unordered_map<int, Positions> islands;

        vector<int> nIslands;

        for (auto& p : positions) {
            // check neighbor islands
            set<int> ids;
            if (p.first > 0) ids.insert(grid[p.first - 1][p.second]);
            if (p.first < m - 1) ids.insert(grid[p.first + 1][p.second]);
            if (p.second > 0) ids.insert(grid[p.first][p.second - 1]);
            if (p.second < n - 1) ids.insert(grid[p.first][p.second + 1]);
            ids.erase(-1); // remove invalid island id

            // get final island id
            int id;
            if (ids.empty()) {
                // a new island
                id = p.first * n + p.second;
                islands.emplace(id, Positions());
            } else if (ids.size() == 1) {
                // one island
                id = *ids.begin();
             } else {
                // multiple islands, merge
                id = myMergeIslands(ids, islands, grid);
            }

            // add point to island
            islands[id].push_back(p);
            grid[p.first][p.second] = id;

            nIslands.push_back(islands.size());
        }

        return nIslands;
    }

private:
    int myMergeIslands(const set<int>& ids, unordered_map<int, Positions>& islands, Grid& grid) {
        int id = *ids.cbegin();

        auto it = ids.cbegin();
        for (++it; it != ids.cend(); ++it) {
            // update id
            for (auto& p : islands[*it]) {
                grid[p.first][p.second] = id;
            }

            // merge islands
            islands[id].insert(islands[id].end(), islands[*it].begin(), islands[*it].end());
            islands.erase(*it);
        }

        return id;
    }
};
