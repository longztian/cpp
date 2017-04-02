class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() < 5) return preorder == "#";

        stack<pair<bool, bool>> validNodes;
        validNodes.push({true, false});  // dummy root with a dummy left child

        auto pb = preorder.data(), pe = pb;
        const auto PE = pb + preorder.size();

        while (pb < PE && !validNodes.empty()) {
            if (*pb != '#') {  // live node
                pe = find(pb, PE, ',');
                validNodes.push({false, false});

            } else {
                pe = pb + 1;  // null node
                while (!validNodes.empty() && validNodes.top().first == true) validNodes.pop();
                if (!validNodes.empty()) validNodes.top().first = true;
            }

            pb = pe + 1;
        }

        return pe == PE && validNodes.empty();
    }
};


class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() < 5) return preorder == "#";

        stack<bool> leftValidated;
        leftValidated.push(true);

        auto pb = preorder.data();
        const auto PE = pb + preorder.size();

        while (pb < PE && !leftValidated.empty()) {
            if (*pb != '#') {
                leftValidated.push(false);

                pb = find(pb, PE, ',') + 1;
            } else {
                while (!leftValidated.empty() && leftValidated.top() == true) leftValidated.pop();
                if (!leftValidated.empty()) leftValidated.top() = true;

                pb += 2;
            }
        }

        return pb == PE + 1 && leftValidated.empty();
    }
};
