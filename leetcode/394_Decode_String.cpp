class Solution {
public:
    string decodeString(string s) {
        // stack for square brackets
        // digit is a start of an encoded chunk
        std::stringstream ss;
        const std::locale loc;

        const auto ITE = s.cend();
        auto itb = s.cbegin(), it = itb, ite = itb;
        int n = 0, nOpen = 0;

        while (itb != ITE) {
            // find digit
            it = std::find_if(itb, ITE, [&](char c) { return std::isdigit(c, loc); });
            if (it == ITE) {
                ss << string(itb, it);
                break;
            };
            if (it != itb) ss << string(itb, it);

            ite = std::find(it, ITE, '[');
            n = std::stoi(string(it, ite));

            // find chunk
            itb = ite + 1;
            nOpen = 1;
            for (it = itb; nOpen && it != ITE; ++it) {
                if (*it == '[') ++nOpen;
                else if (*it == ']') --nOpen;
            }
            ite = it - 1;

            // decode chunk
            string decoded = decodeString(string(itb, ite));

            // repeat decoded chunk
            while (n--) ss << decoded;

            itb = ite + 1;
        }

        return ss.str();
    }
};
