int myFactorial(int n) {
    static bool init = false;
    static vector<int> factorial(500, 0);

    if (init == false) {
        factorial[1] = 1;
        for (int i = 2; i < 500; ++i) {
            factorial[i] = i * factorial[i - 1];
        }
        init = true;
    }

    return factorial[n];

}

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.size() < 3) return 0;

        int n = points.size();
        vector<vector<int>> distMatrix(n, vector<int>(n, 0));

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                distMatrix[i][j] = distMatrix[j][i] = myDistPower2(points[i], points[j]);
            }
        }

        vector<map<int, int>> distCounts(n, map<int, int>());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) distCounts[i][distMatrix[i][j]] += 1;
            }
        }

        int nb = 0;
        for (auto& dc : distCounts) {
            for (auto it = dc.begin(); it != dc.end(); ++it) {
                if (it->second > 1) nb += myFactorial(it->second);
            }
        }

        return nb;
    }

private:
    int myDistPower2(pair<int, int>& i, pair<int, int>& j) {
        return (i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second);
    }
};
