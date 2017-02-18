using Node = pair<int, int>;
auto comp = [](const Node& lhs, const Node& rhs) {
    return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second < rhs.second;
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        const auto ITB = people.begin(), ITE = people.end();

        std::sort(ITB, ITE, comp);

        auto it = std::lower_bound(ITB, ITE, std::make_pair(0, 1), comp);

        std::vector<Node> ret;
        ret.reserve(people.size());
        ret.insert(ret.begin(), ITB, it);

        int n;
        std::vector<Node>::iterator itInsert, itEnd;
        while (it != ITE) {
            // insert it
            n = it->second + 1;  // find the upper_bound
            itInsert = ret.begin();
            itEnd = ret.end();

            while (n && itInsert != itEnd) {
                if (itInsert->first >= it->first) --n;
                ++itInsert;
            }

            if (n == 0) --itInsert;  // found n nodes, insert at upper_bound

            ret.insert(itInsert, *it);

            ++it;
        }

        return ret;
    }
};
