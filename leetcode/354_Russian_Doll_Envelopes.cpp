class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>& lhs, pair<int, int>& rhs) {
            return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
        });

        int maxN = INT_MIN;
        vector<int> doll;
        myDP(envelopes, 0, doll, maxN);

        return maxN;
    }

private:
    void myDP(const vector<pair<int, int>>& envelopes, int i, vector<int>& doll, int& maxN) {
        if (i == envelopes.size()) {
            maxN = max(maxN, (int) doll.size());
            return;
        }

        bool isBig;
        for (int j = i; j < envelopes.size(); ++j) {
            isBig = doll.empty()
                    || (envelopes[j].first > envelopes[doll.back()].first
                        && envelopes[j].second > envelopes[doll.back()].second);

            if (isBig) doll.push_back(j);

            myDP(envelopes, j + 1, doll, maxN);

            if (isBig) doll.pop_back();
        }
    }
};
