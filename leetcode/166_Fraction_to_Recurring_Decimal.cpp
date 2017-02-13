class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "NaN";
        if (numerator == 0) return "0";

        long num = static_cast<long>(numerator), denom = static_cast<long>(denominator);
        bool negative = false;

        if (num < 0) {
            num *= -1;
            negative = !negative;
        }
        if (denom < 0) {
            denom *= -1;
            negative = !negative;
        }

        std::stringstream ss;

        if (negative) ss << '-';

        ss << num / denom;

        num %= denom;
        if (num) ss << '.';

        std::vector<int> digits;
        std::unordered_map<int, int> digitIndexes;
        auto it = digitIndexes.end();
        while (num) {
            it = digitIndexes.find(num);
            if (it == digitIndexes.end()) {
                digitIndexes.emplace(num, digits.size());

                num *= 10;
                digits.push_back(num / denom);
                num %= denom;
            } else {
                break;  // found recursion
            }
        }

        if (it == digitIndexes.end()) {
            for (auto d : digits) ss << d;
        } else {
            for (int i = 0, n = it->second; i < n; ++i) ss << digits[i];
            ss << '(';
            for (int i = it->second, n = digits.size(); i < n; ++i) ss << digits[i];
            ss << ')';
        }

        return ss.str();
    }
};
