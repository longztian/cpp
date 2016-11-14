class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string copy(str);
        copy.append(str);
        return copy.find(str, 1) < str.size();
    }
};
