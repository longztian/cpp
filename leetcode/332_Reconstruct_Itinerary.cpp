class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // populate <string, id> lookup table
        unordered_map<string, int> ids;
        vector<string> airports;
        myBuildStringLookup(tickets, ids, airports);

        // build graph
        vector<vector<int>> g(ids.size(), vector<int>(ids.size(), 0));
        for (const auto& p : tickets) ++g[ids[p.first]][ids[p.second]];

        // depth first traverse
        const int N = tickets.size() + 1;
        vector<int> path(1, ids["JFK"]);
        path.reserve(N);

        myConnect(g, path, N);

        // convert id to string
        vector<string> ret(path.size());
        for (int i = 0; i < path.size(); ++i) ret[i] = airports[path[i]];

        return ret;
    }

private:
    void myBuildStringLookup(const vector<pair<string, string>>& inputs,
                             unordered_map<string, int>& ids, vector<string>& strings) {
        set<string> stringSet;
        for (const auto& p : inputs) {
            stringSet.insert(p.first);
            stringSet.insert(p.second);
        }

        strings.insert(strings.begin(), stringSet.begin(), stringSet.end());
        for (int i = 0; i < strings.size(); ++i) ids.emplace(strings[i], i);
    }

    void myConnect(vector<vector<int>>& g, vector<int>& path, const int N) {
        auto& row = g[path.back()];

        for (int i = 0; i < row.size(); ++i) {
            if (row[i]) {
                path.push_back(i);
                --row[i];

                myConnect(g, path, N);
                if (path.size() == N) return;

                path.pop_back();
                ++row[i];
            }
        }
    }
};
