class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // queue with descending order
        const auto comp = [&matrix](const pair<int, int>& lhs, const pair<int, int>& rhs){
            return matrix[lhs.first][lhs.second] > matrix[rhs.first][rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);

        const int N = matrix.size();
        vector<vector<bool>> added(N + 1, vector<bool>(N + 1, false));

        // mark boundary cell as added
        for (auto& r : added) r[N] = true;
        std::fill(added.back().begin(), added.back().end(), true);

        const auto addOnce = [&added, &q](const int i, const int j) {
            if (!added[i][j]) {
                q.push({i, j});
                added[i][j] = true;
            }
        };

        addOnce(0, 0);
        int i, j, val;
        do {
            i = q.top().first;
            j = q.top().second;
            q.pop();

            val = matrix[i][j];

            addOnce(i + 1, j);
            addOnce(i, j + 1);
        } while (--k);

        return val;
    }
};
