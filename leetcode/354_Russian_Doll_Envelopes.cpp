// O(N^2)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        const int N = envelopes.size();
        if (N < 2) return N;

        sort(envelopes.begin(), envelopes.end());

        vector<int> counts(N, 1);

        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    counts[i] = max(counts[i], counts[j] + 1);
                }
            }
        }

        return *max_element(counts.begin(), counts.end());
    }
};


// O(Nlog(N))
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        const int N = envelopes.size();
        if (N < 2) return N;

        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& lfs, const pair<int, int>& rhs) {
            return lfs.first != rhs.first ? lfs.first < rhs.first : lfs.second > rhs.second;
        });

        vector<int> tails;
        auto it = tails.end();
        for (const auto& env : envelopes) {
            it = lower_bound(tails.begin(), tails.end(), env.second);
            if (it == tails.end()) tails.push_back(env.second);
            else *it = env.second;
        }

        return tails.size();
    }
};
