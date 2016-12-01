using WordMap = unordered_set<string>;
using CacheMap = unordered_map<const char*, bool>;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty()) return false;
        CacheMap cache;
        return myWordBreak(s.data(), s.data() + s.size(), wordDict, cache);
    }

private:
    bool myWordBreak(const char* b, const char* e, const WordMap& wordDict, CacheMap& cache) {
        auto it = cache.find(b);
        if (it != cache.end()) return it->second;

        bool canBreak = false;
        if (b < e) {
            for (auto& w : wordDict) {
                if (strncmp(b, w.data(), w.size()) == 0
                    && (b + w.size() == e || myWordBreak(b + w.size(), e, wordDict, cache))) {
                        canBreak = true;
                        break;
                }
            }
        }

        cache[b] = canBreak;
        return canBreak;
    }
};
