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
                    throw runtime_error("input error");
                }
            }
        }

        return maxlen;
    }
};


class Solution {
public:
    int lengthLongestPath(string input) {
        std::vector<int> levelLengths(1, -1); // remove the leading slash

        int level = 0;
        int length = 0;
        int maxLength = 0;

        auto itLineB = input.cbegin();
        auto itLineE = itLineB;
        const auto itE = input.cend();

        bool isFile = false;

        while (itLineE != itE) {
            itLineE = std::find(itLineB, itE, '\n');

            level = 1;
            while (itLineB < itLineE && *itLineB == '\t') {
                ++level;
                ++itLineB;
            }
            while (levelLengths.size() <= level) levelLengths.push_back(0);

            length = levelLengths[level - 1] + std::distance(itLineB, itLineE) + 1; // add a slash

            isFile = std::find(itLineB, itLineE, '.') != itLineE;

            if (isFile) maxLength = std::max(length, maxLength);
            else levelLengths[level] = length;

            itLineB = itLineE + 1;
        }

        return maxLength;
    }
};

// this is a directory tree, with a preorder traversal representation
// preorder
/*
void myPreorder(root) {
   // visit root
   root->val;
   myPreOrder(root->left);
   myPreOrder(root->right);
}

void myPreorder(root) {
  vector<int> stack;
  if (root) stack.push_back(root);
  while (!stack.empty()) {
    // visit root
    auto p = stack.back();
    stack.pop_back();

    if (root->right) stack.push_back(p->right);
    if (root->left) stack.push_back(p->left);
  }
}
*/



