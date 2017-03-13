class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 1) return {};

        vector<string> ret;

        string curr;
        curr.reserve(n * 2);

        myBacktracking(n, n, curr, ret);

        return ret;
    }

private:
    void myBacktracking(size_t left, size_t right, string& curr, vector<string>& all) {
        if (right < left) return;

        if (left == 0) {
            all.push_back(curr);
            all.back().append(right, ')');
            return;
        }

        curr.append(1, '(');
        myBacktracking(left - 1, right, curr, all);
        curr.pop_back();

        curr.append(1, ')');
        myBacktracking(left, right - 1, curr, all);
        curr.pop_back();
    }
};
