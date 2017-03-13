/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode*> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    using Node = UndirectedGraphNode;

    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == nullptr) return nullptr;

        unordered_map<const Node*, Node*> map;

        stack<Node*> stk;
        stk.push(node);

        Node* p = nullptr;
        while (!stk.empty()) {
            p = stk.top();
            stk.pop();

            if (map.find(p) == map.end()) {
                map[p] = new Node(p->label);
                map[p]->neighbors = p->neighbors;

                for (auto pn : p->neighbors) stk.push(pn);
            }
        }

        for (auto& v : map) {
            auto& nbs = v.second->neighbors;
            transform(nbs.begin(), nbs.end(), nbs.begin(), [&map](const Node* p) { return map[p]; });
        }

        return map[node];
    }
};
