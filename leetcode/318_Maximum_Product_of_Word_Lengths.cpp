class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int N = words.size();
        if (N < 2) return 0;

        vector<bitset<26>> wordBits(N);
        vector<int> wordLens(N);
        for (auto i = 0; i < N; ++i) {
            for (auto c : words[i]) wordBits[i][c - 'a'] = 1;
            wordLens[i] = words[i].size();
        }

        int maxLen = 0;
        for (auto i = 0; i < N - 1; ++i) {
            for (auto j = i + 1; j < N; ++j) {
                if ((wordBits[i] & wordBits[j]) == 0) maxLen = max(maxLen, wordLens[i] * wordLens[j]);
            }
        }

        return maxLen;
    }
};
