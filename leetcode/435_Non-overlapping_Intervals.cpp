/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool myComp(const Interval& i1, const Interval& i2) {
    return i1.end < i2.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int N = intervals.size();
        if (N < 2) return 0;

        sort(intervals.begin(), intervals.end(), myComp);

        int n = 0, end = intervals[0].start;
        for (auto& it : intervals) {
            if (it.start < end) {
                n += 1;
            } else {
                end = it.end;
            }
        }

        return n;
    }
};


/*
 * order by start, need to scan from the back.
 * if order by start descendingly, then we can scan from the beginning.
 */
bool myComp(const Interval& i1, const Interval& i2) {
    return i1.start > i2.start;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int N = intervals.size();
        if (N < 2) return 0;

        sort(intervals.begin(), intervals.end(), myComp);

        int n = 0, start = intervals[0].end;
        for (auto& it : intervals) {
            if (it.end > start) {
                n += 1;
            } else {
                start = it.start;
            }
        }

        return n;
    }
};
