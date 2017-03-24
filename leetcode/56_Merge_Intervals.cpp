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
        const int N = intervals.size();
        if (N < 2) return intervals;

        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.start != rhs.start ? lhs.start < rhs.start : lhs.end < rhs.end;
        });

        vector<Interval> ret(1, intervals[0]);

        for (int i = 1; i < N; ++i) {
            if (intervals[i].start <= ret.back().end) {
                ret.back().end = max(intervals[i].end, ret.back().end);
            } else {
                ret.push_back(intervals[i]);
            }
        }

        return ret;
    }
};

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
        vector<Interval> ret;

        for (auto& v : intervals) myMerge(ret, v.start, v.end);

        return ret;
    }

private:
    void myMerge(vector<Interval>& intervals, int start, int end) {
        auto itb = lower_bound(intervals.begin(), intervals.end(), Interval(start, start),
                               [](const Interval& lhs, const Interval& rhs) {
                                   return lhs.end < rhs.end;
                               });
        auto ite = upper_bound(intervals.begin(), intervals.end(), Interval(end, end),
                               [](const Interval& lhs, const Interval& rhs) {
                                   return lhs.start < rhs.start;
                               });

        if (itb == ite) {
            intervals.insert(itb, Interval(start, end));
        } else {
            itb->start = min(itb->start, start);
            itb->end = max((ite - 1)->end, end);
            intervals.erase(itb + 1, ite);
        }
    }
};
