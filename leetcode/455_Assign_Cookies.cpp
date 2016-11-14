class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.empty() || s.empty()) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = g.size() - 1, j = s.size() - 1;
        while (i >= 0 && j >= 0) {
            if (s[j] >= g[i]) --j;
            --i;
        }

        return s.size() - j - 1;
    }
};
