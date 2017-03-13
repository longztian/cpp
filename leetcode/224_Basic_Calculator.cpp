class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;

        vector<bool> plus;
        plus.push_back(true);

        int total = 0, factor = 1;
        for (auto p = const_cast<char*>(s.data()), PE = p + s.size(); p < PE; ++p) {
            switch(*p) {
                case ' ': break;
                case '+': factor = plus.back() ? 1 : -1; break;
                case '-': factor = plus.back() ? -1 : 1; break;
                case '(': plus.push_back(factor > 0 ? true : false); break;
                case ')': plus.pop_back(); break;
                default: total += (factor * strtol(p, &p, 10)); --p;
            }
        }

        return total;
    }
};
