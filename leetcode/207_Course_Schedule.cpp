// first colution, similar to BFS In-Degree, from two ends;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> heads, tails;
        vector<int> headCount(numCourses, 0), tailCount(numCourses, 0);
        for (auto& edge : prerequisites) {
            headCount[edge.first] += 1;
            tailCount[edge.second] += 1;
            heads[edge.second].push_back(edge.first);
            tails[edge.first].push_back(edge.second);
        }

        vector<int> onlyHeads, onlyTails;
        while (true) {
            onlyHeads.clear();
            onlyTails.clear();
            for (int i = 0; i < numCourses; ++i) {
                if (headCount[i] == 0) onlyTails.push_back(i);
            }
            for (int i = 0; i < numCourses; ++i) {
                if (tailCount[i] == 0) onlyHeads.push_back(i);
            }

            if (onlyHeads.empty() || onlyTails.empty()) break;

            for (int ih : onlyHeads) {
                headCount[ih] = -1;
                tailCount[ih] = -1;
                for (int it : tails[ih]) {
                    tailCount[it] -= 1;
                }
            }
            for (int it : onlyTails) {
                headCount[it] = -1;
                tailCount[it] = -1;
                for (int ih : heads[it]) {
                    headCount[ih] -= 1;
                }
            }
        }

        for (int i : headCount) {
            if (i > 0) return false;
        }

        return true;
    }
};

// DFS circle
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        auto graph = myBuildGraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (myDfsCircle(i, graph, onpath, visited)) return false;
        }

        return true;
    }

private:
    vector<unordered_set<int>> myBuildGraph(int n, const vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& ed : edges) graph[ed.first].insert(ed.second);
        return graph;
    }

    bool myDfsCircle(const int node, const vector<unordered_set<int>>& graph, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;

        visited[node] = true;

        onpath[node] = true;
        for (int i : graph[node]) {
            if (onpath[i]) return true;
            if (myDfsCircle(i, graph, onpath, visited)) return true;
        }
        onpath[node] = false;

        return false;
    }
};

// BFS topologic sort, In-Degree
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        auto graph = myBuildGraph(numCourses, prerequisites);

        vector<int> indegree(numCourses, 0);
        for (auto&  edges : graph) {
            for (int j : edges) indegree[j] += 1;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) que.push(i);
        }

        int i;
        while (!que.empty()) {
            i = que.front();
            indegree[i] = -1;
            for (int j : graph[i]) {
                indegree[j] -= 1;
                if (indegree[j] == 0) que.push(j);
            }
            que.pop();
        }

        return find_if(indegree.begin(), indegree.end(), [](int v) {return v > 0;}) == indegree.end();
    }

private:
    vector<unordered_set<int>> myBuildGraph(int n, const vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& eg : edges) graph[eg.first].insert(eg.second);
        return graph;
    }
};
