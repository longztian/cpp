class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](pair<int, int>& l, pair<int, int>& r) { return l.second < r.second; });

        int nArrow = 1, lastArrow = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first > lastArrow) {
              lastArrow = points[i].second;
              nArrow += 1;
            }
        }
        return nArrow;
    }
};
