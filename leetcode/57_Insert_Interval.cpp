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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        const auto ITB = intervals.begin(), ITE = intervals.end();
        auto itb = lower_bound(ITB, ITE, Interval(newInterval.start, newInterval.start),
                               [](const Interval& lhs, const Interval& rhs) {
                                   return lhs.end < rhs.end;
                               });
        auto ite = upper_bound(itb, ITE, Interval(newInterval.end, newInterval.end),
                               [](const Interval& lhs, const Interval& rhs) {
                                   return lhs.start < rhs.start;
                               });
        if (itb == ite) {
            intervals.insert(itb, newInterval);
        } else {
            itb->start = min(itb->start, newInterval.start);
            itb->end = max((ite - 1)->end, newInterval.end);
            intervals.erase(itb + 1, ite);
        }

        return intervals;
    }
};
