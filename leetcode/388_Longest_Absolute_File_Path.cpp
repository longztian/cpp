class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> length(1, 0);
        bool isFile;
        int level, len, maxlen = 0;

        for (int i = 0, n = input.size(); i < n; ++i) {
            // check level
            level = 0;
            while (i < n && input[i] == '\t') {
                ++level;
                ++i;
            }

            // check file
            len = 0;
            isFile = false;
            while (i < n && input[i] != '\n') {
                if (input[i] == '.') isFile = true;
                ++len;
                ++i;
            }

            // isFile
            if (isFile) {
                maxlen = max(maxlen, length[level] + len);
            } else {
                if (level + 1 < length.size()) {
                    length[level + 1] = length[level] + len + 1;
                } else if (level + 1 == length.size()) {
                    length.push_back(length.back() + len + 1);
                } else {
                    cout << "input error" << endl;
                }
            }
        }

        return maxlen;
    }
};
