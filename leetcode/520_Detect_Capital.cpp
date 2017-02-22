class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;
        for (auto c : word) {
            if (c >= 'A' && c <= 'Z') ++upperCount;
        }

        if (upperCount == 0 || upperCount == word.size()) return true;
        if (upperCount != 1) return false;
        return word[0] >= 'A' && word[0] <= 'Z';
    }
};
