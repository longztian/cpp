class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string& lhs, const string& rhs) {
            lhs.size() == rhs.size() ? lhs < rhs : lhs.size() > rhs.size();
        });

        for (const auto& word : d) {
            if (myContains(s, word)) return word;
        }

        return "";
    }

private:
    bool myContains(const string& s, const string& word) {
        if (s.size() < word.size()) return false;

        const auto ITE = s.end();
        auto it = s.begin();
        for (auto c : word) {
            it = find(it, ITE, c);
            if (it == ITE) return false;
        }

        return true;
    }
};
