struct Cell {
    int x;
    int y;
    int height;

    Cell(int x, int y, int height) : x(x), y(y), height(height) {}
    // bool operator<(const Cell& rhs) const { return height > rhs.height; }
};

namespace std {
template <> struct greater<Cell> {
    bool operator() (const Cell& lhs, const Cell& rhs) const {
        return lhs.height > rhs.height;
    }
};
}

const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int NR = heightMap.size();
        if (NR < 3) return 0;
        const int NC = heightMap.front().size();
        if (NC < 3) return 0;

        std::vector<std::vector<int>> visited(NR, std::vector<int>(NC, 0));
        std::vector<Cell> container;
        for (int j = 0; j < NC; ++j) {
            container.emplace_back(0, j, heightMap[0][j]);
            container.emplace_back(NR - 1, j, heightMap[NR - 1][j]);
            visited[0][j] = 1;
            visited[NR - 1][j] = 1;
        }
        for (int i = 1; i < NR - 1; ++i) {
            container.emplace_back(i, 0, heightMap[i][0]);
            container.emplace_back(i, NC - 1, heightMap[i][NC - 1]);
            visited[i][0] = 1;
            visited[i][NC - 1] = 1;
        }

        std::priority_queue<Cell,
                            std::vector<Cell>,
                            std::greater<Cell>> q(std::greater<Cell>(), std::move(container));

        int water = 0, i, j;
        while (!q.empty()) {
            auto& c = q.top();
            for (auto& d : dir) {
                i = c.x + d.first;
                j = c.y + d.second;

                if (i < 0 || j < 0 || i == NR || j == NC) continue;

                if (visited[i][j] == 0) {
                    if (c.height > heightMap[i][j]) {
                        water += (c.height - heightMap[i][j]);
                        q.emplace(i, j, c.height);
                    } else {
                        q.emplace(i, j, heightMap[i][j]);
                    }
                    visited[i][j] = 1;
                }
            }
            q.pop();
        }

        return water;
    }
};
