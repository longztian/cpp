const size_t N_TOP = 3;

const array<string, N_TOP> MY_TOPS = {
    "Gold Medal",
    "Silver Medal",
    "Bronze Medal"
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        auto ranks = myToRankNodes(nums);

        sort(ranks.begin(), ranks.end(), [](const Node& lhs, const Node& rhs){ return lhs.val > rhs.val; });

        for (size_t i = 0; i < nums.size(); ++i) {
            ranks[i].rank = i;
        }

        auto tops = myGetTopIndexes(ranks, N_TOP);

        sort(ranks.begin(), ranks.end(), [](const Node& lhs, const Node& rhs){ return lhs.index < rhs.index; });

        return myToRankStrings(ranks, tops);
    }

private:
    struct Node {
        size_t index;
        size_t rank;
        int val;

        Node() : index(0), rank(0), val(0) {}
    };

    inline vector<Node> myToRankNodes(const vector<int>& nums) const {
        const size_t N = nums.size();

        vector<Node> ranks(N);

        for (size_t i = 0; i < N; ++i) {
            ranks[i].index = i;
            ranks[i].val = nums[i];
        }

        return ranks;
    }

    inline vector<size_t> myGetTopIndexes(const vector<Node>& ranks, size_t count) const {
        vector<size_t> tops;

        for (size_t i = 0, n = min(ranks.size(), count); i < n; ++i) {
            tops.push_back(ranks[i].index);
        }

        return tops;
    }

    inline vector<string> myToRankStrings(const vector<Node>& ranks, const vector<size_t> topIndexes) const {
        vector<string> rankStrs;

        for (const auto& node : ranks) {
            rankStrs.push_back(to_string(static_cast<long>(node.rank) + 1));
        }

        for (size_t i = 0; i < topIndexes.size(); ++i) {
            rankStrs[topIndexes[i]] = MY_TOPS[i];
        }

        return rankStrs;
    }
};
