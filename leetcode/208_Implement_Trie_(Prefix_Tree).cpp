class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        auto node = &myRoot;

        int i;
        for (auto c : word) {
            if (!node->children) node->children.reset(new TrieNode::children_t());

            i = c - 'a';
            if (!(*node->children)[i]) (*node->children)[i].reset(new TrieNode());

            node = (*node->children)[i].get();
        }

        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        auto node = mySearchPrefix(word);
        return node && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const {
        return mySearchPrefix(prefix) != nullptr;
    }

private:
    // types
    struct TrieNode {
        // types
        using children_t = std::array<std::unique_ptr<TrieNode>, 26>;

        // properties
        std::unique_ptr<children_t> children;
        bool isEnd;

        // methods
        TrieNode() : children(nullptr), isEnd(false) {};
    };

    // properties
    TrieNode myRoot;

    // methods
    const TrieNode* mySearchPrefix(const std::string& prefix) const {
        auto node = &myRoot;

        for (auto c : prefix) {
            if (!node->children) return nullptr;
            if (!(*node->children)[c - 'a']) return nullptr;
            node = (*node->children)[c - 'a'].get();
        }

        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
