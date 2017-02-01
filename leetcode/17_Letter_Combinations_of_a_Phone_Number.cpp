class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;

        if (!digits.empty()) {
            string str(digits.size(), 'a');
            myBackTracking(digits, 0, str, ret);
        }

        return ret;
    }

private:
    void myBackTracking(const string& digits, int index, string& str, vector<string>& ret) {
        if (index < digits.length()) {
            auto i = myIndex(digits[index]);
            if (i < 0 || i >= myNumCharMap.size()) return;

            for (auto c : myNumCharMap[i]) {
                str[index] = c;
                myBackTracking(digits, index + 1, str, ret);
            }
        } else {
            ret.push_back(str);
        }
    }

    inline int myIndex(char c) {
        return c - '2';
    }

    static vector<vector<char>> myNumCharMap;
};

vector<vector<char>> Solution::myNumCharMap = {
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r', 's'},
    {'t','u','v'},
    {'w','x','y', 'z'}
};
