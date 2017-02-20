/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return intervals;

        const auto ITB = intervals.begin(), ITE = intervals.end();
        std::sort(ITB, ITE, [](const Interval& lhs, const Interval& rhs) {
            return lhs.start == rhs.start ? lhs.end < rhs.end : lhs.start < rhs.start;
        });

        vector<Interval> ret;
        ret.push_back(*ITB);

        for (auto it = ITB + 1; it != ITE; ++it) {
            if (it->start <= ret.back().end) {
                if (it->end > ret.back().end) ret.back().end = it->end;
            } else {
                ret.push_back(*it);
            }
        }

        return ret;
    }
};
