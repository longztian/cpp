class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
         * start from top right corner
         */
        int r = 0, c = matrix[0].size() - 1;
        while( r < matrix.size() && c >= 0 )
        {
            if( matrix[r][c] == target ) return true;

            if( matrix[r][c] > target )
            {
                --c;
            }
            else
            {
                ++r;
            }
        }

        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix.front().empty()
            || target < matrix.front().front()
            || target > matrix.back().back()) return false;

        const auto ITB = std::lower_bound(matrix.begin(), matrix.end(), vector<int>(1, target),
                                        [](const vector<int>& lhs, const vector<int>& rhs) {
                                            return lhs.back() < rhs.back();
                                        });

        const auto ITE = std::upper_bound(matrix.begin(), matrix.end(), vector<int>(1, target),
                                        [](const vector<int>& lhs, const vector<int>& rhs) {
                                            return lhs.front() < rhs.front();
                                        });

        for (auto it = ITB; it != ITE; ++it) {
            if (binary_search(it->begin(), it->end(), target)) return true;
        }

        return false;
    }
};
