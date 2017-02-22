const vector<int> MASKS = {
    1 << 0,
    1 << 1,
    1 << 2,
    1 << 3,
    1 << 4,
    1 << 5
};

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        if (num < 0 || num > 8) return ret;

        int m;
        vector<string> hours, minutes;
        for (int h = 0; h < 4; ++h) {
            m = num - h;
            if (m < 0 || m > 5) continue;

            hours.clear();
            minutes.clear();

            for (auto v : myValues(h, 4)) {
                if (v < 12) hours.push_back(std::to_string(v) + ':');
            }

            for (auto v : myValues(m, 6)) {
                if (v < 60) minutes.push_back(v > 9 ? std::to_string(v) : string("0") + std::to_string(v));
            }

            for (const auto& hour : hours) {
                for (const auto& minute : minutes) {
                    ret.push_back(hour + minute);
                }
            }
        }

        return ret;
    }

private:
    vector<int> myValues(const int nOnes, const int nDigits) {
        vector<int> values;

        vector<int> digits(nDigits, 0);
        std::fill_n(digits.begin(), nOnes, 1);

        int v;
        do {
            v = 0;
            for (int i = 0; i < nDigits; ++i) v += digits[i] * MASKS[i];
            values.push_back(v);
        } while (std::prev_permutation(digits.begin(), digits.end()));

        return values;
    }
};
