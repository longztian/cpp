class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto pNode = &myRoot;
        for (auto ch : word) {
            if (pNode->children == nullptr) {
                pNode->children.reset(new TrieNode::children_t());
            }

            auto& pNext = (*pNode->children)[ch - 'a'];
            if (pNext == nullptr) {
                pNext.reset(new TrieNode());
            }

            pNode = pNext.get();
        }

        pNode->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto pNode = mySearchPrefix(word);
        return pNode && pNode->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return mySearchPrefix(prefix) != nullptr;
    }

private:
    // types
    struct TrieNode {
        using p_node_t = unique_ptr<TrieNode>;
        using children_t = array<p_node_t, 26>;

        unique_ptr<children_t> children;
        bool isEnd;

        TrieNode() : children(nullptr), isEnd(false) {}
    };

    // properties
    TrieNode myRoot;

    // methods
    const TrieNode* mySearchPrefix(const string& str) const {
        const auto* pNode = &myRoot;

        for (auto ch : str) {
            if (pNode->children == nullptr) return nullptr;
            auto& pNext = (*pNode->children)[ch - 'a'];
            if (pNext == nullptr) return  nullptr;

            pNode = pNext.get();
        }

        return pNode;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
