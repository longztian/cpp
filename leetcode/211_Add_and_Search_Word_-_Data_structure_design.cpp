class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(const string& word) {
        auto node = &myRoot;

        int i;
        for (auto c : word) {
            if (!node->children) node->children.reset(new TrieNode::children_t());

            i = c - 'a';
            auto& children = *node->children;
            if (!children[i]) children[i].reset(new TrieNode());

            node = children[i].get();
        }

        node->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string& word) const {
        return mySearch(&myRoot, word.data(), word.data() + word.size());
    }

private:
    struct TrieNode {
        using children_t = std::array<std::unique_ptr<TrieNode>, 26>;

        std::unique_ptr<children_t> children;
        bool isEnd;

        TrieNode() : children(nullptr), isEnd(false) {};
    };

    TrieNode myRoot;

    bool mySearch(const TrieNode* node, const char* pb, const char* pe) const {
        int i;
        while (pb != pe) {
            if (!node->children) return false;

            if (*pb == '.') {
                for (auto& c : *node->children) {
                    if (!c) continue;
                    if (mySearch(c.get(), pb + 1, pe)) return true;
                }
                return false;
            } else {
                auto& children = *node->children;
                i = *pb - 'a';
                if (!children[i]) return false;
                node = children[i].get();
            }

            ++pb;
        }

        return node->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
