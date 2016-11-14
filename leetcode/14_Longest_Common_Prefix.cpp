class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int N = INT_MAX;
        for (auto& s : strs) {
            if (s.size() < N) N = s.size();
        }

        string prefix = strs[0].substr(0, N);
        for (int i = 1; i < strs.size() && !prefix.empty(); ++i) {
            myPrefix(&strs[i], &prefix);
        }

        return prefix;
    }
private:
    void myPrefix(const string* str, string* prefix) {
        int i = 0;
        while (i < prefix->size()) {
            if ((*str)[i] != (*prefix)[i]) break;
            ++i;
        }

        if (i < prefix->size()) prefix->resize(i);
    }
};
