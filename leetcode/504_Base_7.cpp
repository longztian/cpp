class Solution {
public:
    string convertTo7(int num) {
        if (num == 0) return std::string("0");

        bool negative = num < 0;
        if (negative) num *= -1;

        std::stringstream ss;
        while (num) {
            ss << num % 7;
            num /= 7;
        }
        if (negative) ss << '-';

        auto s = ss.str();
        std::reverse(s.begin(), s.end());

        return s;
    }
};
