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


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.empty()) return ret;

        const auto PE = nums.data() + nums.size();
        auto pb = nums.data(), pe = pb + 1;
        while (pb < PE) {
            while (pe < PE && *(pe - 1) + 1 == *pe) ++pe;

            if (pe - pb == 1) ret.push_back(std::to_string(*pb));
            else ret.push_back(std::to_string(*pb) + "->" + std::to_string(*(pe -1)));

            pb = pe++;
        }

        return ret;
    }
};
