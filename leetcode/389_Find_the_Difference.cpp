class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(26, 0);

        for (auto c : t) ++count[c - 'a'];
        for (auto c : s) --count[c - 'a'];

        return std::distance(count.begin(), std::find(count.begin(), count.end(), 1)) + 'a';
    }
};
