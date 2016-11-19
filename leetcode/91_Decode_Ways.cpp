class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int dp_2 = 1, // i = -1, 1 string, "", contains 0 digit
            dp_1 = 1, // i = 0, 1 string, "n", contains 1 digit
            dp;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i - 1] != '1' && s[i - 1] != '2') return 0;

                dp = dp_2;
            } else if (s[i - 1] != '1' && s[i - 1] != '2') {
                dp = dp_1;
            } else {
                dp = dp_1;
                if (!(s[i - 1] == '2' && s[i] > '6')) dp += dp_2;
            }

            dp_2 = dp_1;
            dp_1 = dp;
        }

        return dp_1;
    }
};
