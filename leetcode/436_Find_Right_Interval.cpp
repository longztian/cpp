/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct IntervalIndex {
    Interval* pInt;
    int index;
    IntervalIndex(Interval* p, int id): pInt(p), index(id) {}
};

bool myComp(const IntervalIndex& i1, const IntervalIndex& i2) {
    return i1.pInt->start == i2.pInt->start ? i1.index < i2.index : i1.pInt->start < i2.pInt->start;
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int N = intervals.size();
        vector<IntervalIndex> intIdx;
        intIdx.reserve(N);
        for (int i = 0; i < N; ++i) {
            intIdx.emplace_back(&intervals[i], i);
        }

        sort(intIdx.begin(), intIdx.end(), myComp);

        vector<int> rightIndexes(N, -1);
        auto pe = intIdx.data() + N;
        Interval tmp(0, numeric_limits<int>::min());
        IntervalIndex v(&tmp, 0);

        for (int i = 0; i < N; ++i) {
            v.pInt->start = intIdx[i].pInt->end;
            auto it = lower_bound(intIdx.data() + i, pe, v, myComp);
            if (it != pe) rightIndexes[intIdx[i].index] = it->index;
        }

        return rightIndexes;
    }
};
