class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        if (nums.empty()) return ranges;

        Range r(nums.front(), nums.front());

        for (auto it = nums.cbegin() + 1, ite = nums.cend(); it != ite; ++it) {
            if (*it != ++r.end) {
                --r.end;
                ranges.push_back(r.toString());
                r.begin = r.end = *it;
            }
        }

        ranges.push_back(r.toString());

        return ranges;
    }

private:
    struct Range {
        int begin;
        int end;

        Range(int begin, int end) : begin(begin), end(end) {};

        string toString() {
            stringstream ss;
            ss << begin;
            if (end > begin) ss << "->" << end;
            return ss.str();
        }
    };
};
