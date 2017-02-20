using Graph = unordered_map<string, unordered_map<string, double>>;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        Graph g;

        const int N = equations.size();
        for (int i = 0; i < N; ++i) {
            g[equations[i].first][equations[i].second] = values[i];
            g[equations[i].second][equations[i].first] = 1 / values[i];
        }

        const auto ITE = g.end();

        vector<double> ret;
        unordered_set<string> visited;
        for (const auto& q : queries) {
            visited.clear();
            ret.push_back(myDfs(q.first, q.second, g, ITE, visited));
        }

        return ret;
    }

private:
    double myDfs(const string& begin, const string& end, const Graph& g, const Graph::iterator ITE, unordered_set<string>& visited) {
        auto it = g.find(begin);
        if (it == ITE) return -1.0;
        if (begin == end) return 1.0;

        auto itv = it->second.find(end);
        if (itv != it->second.end()) return itv->second;

        visited.insert(begin);
        double res;
        for (const auto& v : it->second) {
            if (visited.find(v.first) != visited.end()) continue;

            res = myDfs(v.first, end, g, ITE, visited);
            if (res > 0) return res * v.second;
        }

        return -1.0;
    }
};
