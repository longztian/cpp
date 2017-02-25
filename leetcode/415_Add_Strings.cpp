class Solution {
public:
    string addStrings(const string& num1, const string& num2) {
        if (num1.size() < num2.size()) return addStrings(num2, num1);

        auto ret = num1;

        const auto PE2 = num2.rend();
        auto p1 = ret.rbegin();
        auto p2 = num2.rbegin();
        auto val = 0;
        while (p2 != PE2) {
            *p1 += (static_cast<int>(*p2 - '0') + val);
            if (*p1 > '9') {
                *p1 -= 10;
                val = 1;
            } else {
                val = 0;
            }

            ++p1;
            ++p2;
        }

        const auto PE1 = ret.rend();
        while (p1 != PE1 && val) {
            if (*p1 != '9') {
                *p1 += 1;
                val = 0;
            } else {
                *p1 = '0';
            }

            ++p1;
        }

        if (val) ret.insert(ret.begin(), '1');

        return ret;
    }
};
