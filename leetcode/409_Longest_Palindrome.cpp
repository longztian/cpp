class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counts(256, 0);

        for (auto c : s) ++counts[c];

        const int mask = ~1;
        int n = 0;
        for (auto c = 'a'; c <= 'z'; ++c) n += (counts[c] & mask);
        for (auto c = 'A'; c <= 'Z'; ++c) n += (counts[c] & mask);

        auto it = std::find_if(counts.cbegin(), counts.cend(), [](const int i) { return i % 2 != 0; });
        if (it != counts.cend()) ++n;

        return n;
    }
};
