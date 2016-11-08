class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n < 3) return 0;

        int nb = 0;
        long dx, dy;
        for (int i = 0; i < n; ++i) {
            unordered_map<long, int> distCounts;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                dx = ((long) points[i].first - points[j].first);
                dy = ((long) points[i].second - points[j].second);

                distCounts[dx*dx + dy*dy] += 1;
            }

            for (auto& dc : distCounts) {
                nb += dc.second * (dc.second - 1);
            }
        }

        return nb;
    }
};
