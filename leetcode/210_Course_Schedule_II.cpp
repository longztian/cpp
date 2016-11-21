// BFS topological sort, In-Degree, queue, add head/root first
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        auto graph = myBuildGraph(numCourses, prerequisites);
        auto indegree = myBuildInDegree(graph);

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> toposort(numCourses);
        int n = numCourses;

        while (!q.empty()) {
            toposort[--n] = q.front();
            for (int i : graph[q.front()]) {
                --indegree[i];
                if (indegree[i] == 0) q.push(i);
            }
            q.pop();
        }

        return n == 0 ? toposort : vector<int>();
    }

private:
    vector<unordered_set<int>> myBuildGraph(int n, const vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& eg : edges) graph[eg.first].insert(eg.second);
        return graph;
    }

    vector<int> myBuildInDegree(const vector<unordered_set<int>>& graph) {
        vector<int> indegree(graph.size(), 0);

        for (auto& ends : graph) {
            for (int i : ends) ++indegree[i];
        }

        return indegree;
    }
};

// DFS, stack, add tail/leaf first
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        auto graph = myBuildGraph(numCourses, prerequisites);

        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        vector<int> toposort;
        toposort.reserve(numCourses);

        for (int i = 0; i < numCourses; ++i) {
            if (myDfsCircle(i, graph, onpath, visited, toposort)) return vector<int>();
        }

        return toposort;
    }

private:
    vector<unordered_set<int>> myBuildGraph(int n, const vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& ed : edges) graph[ed.first].insert(ed.second);
        return graph;
    }

    bool myDfsCircle(int node, const vector<unordered_set<int>>& graph, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) {
        if (visited[node]) return false;
        visited[node] = true;

        onpath[node] = true;
        for (int i : graph[node]) {
            if (onpath[i]) return true;
            if (myDfsCircle(i, graph, onpath, visited, toposort)) return true;
        }
        onpath[node] = false;

        toposort.push_back(node);

        return false;
    }
};
