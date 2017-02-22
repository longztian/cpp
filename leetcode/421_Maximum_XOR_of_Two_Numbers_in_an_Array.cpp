class Trie {
public:
    void insert(int n) {
        auto node = &myRoot;
        int bit;
        for (int i = 31; i >= 0; --i) {
            bit = (n >> i) & 1;
            if (!node->children[bit]) node->children[bit].reset(new TrieNode());

            node = node->children[bit].get();
        }
    }

    int maxXOR(int n) const {
        auto node = &myRoot;

        int ret = 0;

        int bit;
        for (int i = 31; i >= 0; --i) {
            bit = (n >> i) & 1 ? 0 : 1;
            if (!node->children[bit]) bit = bit ? 0 : 1;
            else ret |= (1 << i);

            node = node->children[bit].get();
        }

        return ret;
    }

private:
    struct TrieNode {
        using children_t = std::array<std::unique_ptr<TrieNode>, 2>;

        children_t children;
    };

    TrieNode myRoot;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for (auto n : nums) t.insert(n);

        int maxXOR = INT_MIN;
        for (auto n : nums) maxXOR = std::max(maxXOR, t.maxXOR(n));

        return maxXOR;
    }
};
