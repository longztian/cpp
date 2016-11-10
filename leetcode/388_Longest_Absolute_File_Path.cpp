class Solution {
public:
    struct Node;
    using NodePtr = shared_ptr<Node>;

    struct Node {
        int length;
        NodePtr parent;
        vector<NodePtr> children;

        Node(NodePtr p) : length(0), parent(p) {}
        Node(int len) : length(len), parent(nullptr) {}
        Node(int len, NodePtr p) : length(len), parent(p) {}
    };

    int lengthLongestPath(string input) {
        const char *pb = input.data(), *pe, *end = input.data() + input.size();
        bool isFile = false;

        while (pe < end && *pe != '\n' ) {
            if (*pe == '.') isFile = true;
            ++pe;
        }
        pb = pe + 1;

        if (isFile) return pe - pb;

        NodePtr root = make_shared<Node>(pe - pb);
        vector<NodePtr> files;

        NodePtr parent = root;
        int level = 1, levelNew;
        while (pb < end) {
            while (pb < end && *pb == '\t') ++pb;
            levelNew = pb - pe - 1;

            if (levelNew > level) {
                // a new child
                NodePtr n = make_shared<Node>(parent);
                parent->children.push_back(n);

                pe = pb + 1;
                while (pe < end && *pe != '\n') {
                    if (*pe == '.') isFile = true;
                    ++pe;
                }

                if (isFile) files.push_back(n);
                n->length = pe - pb;

                // check next level
                level = levelNew;
                parent = n;
                pb = pe + 1;
            } else {
                // same or upper level
                while (level > levelNew) {
                    parent = parent->parent;
                    level -= 1;
                }

                NodePtr n = make_shared<Node>(parent);
                parent->children.push_back(n);

                pe = pb + 1;
                while (pe < end && *pe != '\n') {
                    if (*pe == '.') isFile = true;
                    ++pe;
                }

                if (isFile) files.push_back(n);

                n->length = pe - pb;
                parent = n;
                pb = pe + 1;
            }
        }

        int len, maxLength = numeric_limits<int>::min();
        for (auto& p : files) {
            len = p->length;
            while (p->parent) {
                p = p->parent;
                len += p->length;
            }
            if (maxLength < len) maxLength = len;
        }

        return len;
    }
};
