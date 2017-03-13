class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> wordIndexes;
        size_t maxLen = 0;
        for (int i = 0, n = wordDict.size(); i < n; ++i) {
            wordIndexes.emplace(wordDict[i], i);
            maxLen = max(maxLen, wordDict[i].size());
        }

        const auto PB = s.data(), PE = PB + s.size();
        unordered_map<const char*, unique_ptr<vector<Ids>>> cache;
        cache[PE] = myMakeUnique();

        auto pIdsVec = myWordBreak(PB, PE, maxLen, wordIndexes, cache);
        vector<string> ret;
        if (pIdsVec) {
            for (auto& ids : *pIdsVec) {
                ret.emplace_back();
                for (auto i : ids) {
                    ret.back().append(wordDict[i] + ' ');
                }
                if (!ret.empty()) ret.back().pop_back();
            }
        }

        return ret;
    }

private:
    using Ids = vector<int>;

    inline unique_ptr<vector<Ids>> myMakeUnique() {
        return unique_ptr<vector<Ids>>(new vector<Ids>());
    }

    vector<Ids>* myWordBreak(const char* const PB, const char* const PE, const size_t maxLen,
                             const unordered_map<string, int>& wordIndexes,
                             unordered_map<const char*, unique_ptr<vector<Ids>>>& cache) {
        // found in cache
        auto it = cache.find(PB);
        if (it != cache.end()) return it->second.get();

        // default
        cache[PB] = nullptr;

        string word;
        word.reserve(maxLen);

        const auto ITWE = wordIndexes.end();
        auto itw = ITWE;
        for (auto p = PB; p < PE && word.size() < maxLen; ++p) {
            word.append(1, *p);
            itw = wordIndexes.find(word);
            // found word
            if (itw != ITWE) {
                auto pIdsVec = myWordBreak(p + 1, PE, maxLen, wordIndexes, cache);

                if (pIdsVec) {
                    if (!cache[PB]) cache[PB] = myMakeUnique();
                    auto& idsVec = *cache[PB];

                    if (pIdsVec->empty()) {
                        idsVec.emplace_back(1, itw->second);
                    } else {
                        for (auto& ids : *pIdsVec) {
                            idsVec.emplace_back(1, itw->second);
                            idsVec.back().insert(idsVec.back().end(), ids.begin(), ids.end());
                        }
                    }
                }
            }
        }

        return cache[PB].get();
    }
};
