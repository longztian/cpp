class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return std::vector<std::pair<int, int>>();

        std::vector<std::pair<int, int>> maxHeights;

        for (const auto& v : buildings) {
            maxHeights.emplace_back(v[0], v[2]);
            maxHeights.emplace_back(v[1], 0);
        }

        std::sort(maxHeights.begin(), maxHeights.end());

        const auto ITB = maxHeights.begin(), ITE = maxHeights.end();
        auto it = ITB, itb = ITB, ite = ITB;
        for (const auto& v : buildings) {
            itb = std::lower_bound(itb, ITE, std::make_pair(v[0], 0));
            ite = std::upper_bound(itb, ITE, std::make_pair(v[1], -1));
            for (it = itb; it != ite; ++it) if (it->second < v[2]) it->second = v[2];
        }

        const int N = maxHeights.size();

        std::vector<std::pair<int, int>> ret;
        ret.reserve(N);
        ret.push_back(maxHeights.front());
        for (int i = 1; i < N; ++i) {
            if (ret.back().second != maxHeights[i].second) ret.push_back(maxHeights[i]);
        }

        return ret;
    }
};
