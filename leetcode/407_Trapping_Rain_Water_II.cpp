class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int M = heightMap.size();
        if (M < 3) return 0;
        const int N = heightMap[0].size();
        if (N < 3) return 0;

        priority_queue<Cell> queue;
        vector<vector<int>> visited(M, vector<int>(N, 0));
        int i = 0, j;
        for (j = 0; j < N; ++j) {
            queue.push(Cell(i, j, heightMap[i][j]));
            visited[i][j] = 1;
        }
        for (i = 1; i < M - 1; ++i) {
            queue.push(Cell(i, 0, heightMap[i][0]));
            queue.push(Cell(i, N - 1, heightMap[i][N - 1]));
            visited[i][0] = 1;
            visited[i][N - 1] = 1;
        }
        i = M - 1;
        for (j = 0; j < N; ++j) {
            queue.push(Cell(i, j, heightMap[i][j]));
            visited[i][j] = 1;
        }


        int water = 0, height;
        while (!queue.empty()) {
            auto cell = queue.top();
            queue.pop();

            if (cell.x > 0 && visited[cell.x - 1][cell.y] == 0) {
                height = heightMap[cell.x - 1][cell.y];
                if (height < cell.height) {
                    water += cell.height - height;
                    height = cell.height;
                }
                queue.push(Cell(cell.x - 1, cell.y, height));
                visited[cell.x - 1][cell.y] = 1;
            }
            if (cell.x < M - 1 && visited[cell.x + 1][cell.y] == 0) {
                height = heightMap[cell.x + 1][cell.y];
                if (height < cell.height) {
                    water += cell.height - height;
                    height = cell.height;
                }
                queue.push(Cell(cell.x + 1, cell.y, height));
                visited[cell.x + 1][cell.y] = 1;
            }
            if (cell.y > 0 && visited[cell.x][cell.y - 1] == 0) {
                height = heightMap[cell.x][cell.y - 1];
                if (height < cell.height) {
                    water += cell.height - height;
                    height = cell.height;
                }
                queue.push(Cell(cell.x, cell.y - 1, height));
                visited[cell.x][cell.y - 1] = 1;
            }
            if (cell.y < N - 1 && visited[cell.x][cell.y + 1] == 0) {
                height = heightMap[cell.x][cell.y + 1];
                if (height < cell.height) {
                    water += cell.height - height;
                    height = cell.height;
                }
                queue.push(Cell(cell.x, cell.y + 1, height));
                visited[cell.x][cell.y + 1] = 1;
            }
        }

        return water;
    }

private:
    struct Cell {
        int x;
        int y;
        int height;

        Cell(int x, int y, int height) : x(x), y(y), height(height) {}

        bool operator<(const Cell& rhs) const {
            return height > rhs.height;
        }
    };
};
