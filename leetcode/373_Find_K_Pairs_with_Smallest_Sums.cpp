class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<pair<int, int>> kSmallest;
        if (N1 * N2 == 0 || k < 1) return kSmallest;

        kSmallest.reserve(k);

        // priority queue in descending order
        const auto greater = [&nums1, &nums2](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return static_cast<long>(nums1[lhs.first]) + nums2[lhs.second] > static_cast<long>(nums1[rhs.first]) + nums2[rhs.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> q(greater);

        vector<vector<bool>> added(N1 + 1, vector<bool>(N2 + 1, false));

        // mark boundary cells as added
        for (auto& r : added) r[N2] = true;
        std::fill(added.back().begin(), added.back().end(), true);

        const auto add = [&added, &q](int i1, int i2) {
            if (!added[i1][i2]) {
                q.push({i1, i2});
                added[i1][i2] = true;
            }
        };

        auto i1 = 0, i2 = 0;
        add(i1, i2);
        do {
            i1 = q.top().first;
            i2 = q.top().second;
            q.pop();

            kSmallest.emplace_back(nums1[i1], nums2[i2]);

            add(i1 + 1, i2);
            add(i1, i2 + 1);
        } while(--k && !q.empty());

        return kSmallest;
    }
};
