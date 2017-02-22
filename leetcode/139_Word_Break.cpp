using WordSet = unordered_set<string>;
using CacheMap = unordered_map<const char*, bool>;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty()) return false;
        CacheMap cache;
        return myWordBreak(s.data(), s.data() + s.size(), wordDict, cache);
    }

private:
    bool myWordBreak(const char* b, const char* e, const WordSet& wordDict, CacheMap& cache) {
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


// DP + cache

class Solution {
public:
    using WordSet = std::unordered_set<std::string>;
    using CacheMap = std::unordered_map<const char*, bool>;

    bool wordBreak(string s, vector<string>& wordDict) {
        WordSet wordSet(wordDict.begin(), wordDict.end());
        CacheMap cache;

        return myWordBreak(s.data(), s.data() + s.size(), wordSet, cache);
    }

private:
    bool myWordBreak(const char* PB, const char* PE, const WordSet& wordSet, CacheMap& cache) {
        auto it = cache.find(PB);
        if (it != cache.end()) return it->second;

        bool canBreak = false;
        if (wordSet.find(string(PB, PE)) != wordSet.end()) canBreak = true;

        for (auto p = PB + 1; !canBreak && p < PE; ++p) {
            if (wordSet.find(string(PB, p)) != wordSet.end()) canBreak = myWordBreak(p, PE, wordSet, cache);
        }

        cache[PB] = canBreak;

        return canBreak;
    }
};
