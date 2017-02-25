using Ptr = const char*;
using Key = std::array<Ptr, 4>;
using Cache = std::unordered_map<Key, bool>;

namespace std {
template<> struct hash<Key> {
    size_t operator()(const Key& k) const {
        return hash<int>()(k[1] - k[0] + k[3] - k[2]);
    }
};
}

class Solution {
public:
    bool isMatch(string s, string p) {
        Cache cache;
        return myIsMatch(s.data(), s.data() + s.size(), p.data(), p.data() + p.size(), cache);
    }

private:
    bool myIsMatch(Ptr psb, Ptr pse, Ptr ppb, Ptr ppe, Cache& cache) {
        const auto key = Key({psb, pse, ppb, ppe});
        auto itc = cache.find(key);
        if (itc != cache.end()) return itc->second;

        bool match = true;

        auto itStar = std::find(ppb, ppe, '*');
        if (itStar == ppe) {
            // no star
            match = myIsMatchSimple(psb, pse, ppb, ppe);
        } else {
            int n = itStar - 1 - ppb;
            if (n) {
                if (pse - psb < n) match = false;
                else match = myIsMatchSimple(psb, psb + n, ppb, ppb + n);
            }

            if (match) {
                // move to star pattern
                psb += n;
                ppb += n;

                if (psb == pse) {
                    if (ppb == ppe) match = true;
                    else match = myIsMatch(psb, pse, ppb + 2, ppe, cache);
                } else {
                    if (*psb == *ppb || *ppb == '.') {
                        // star match
                        match = myIsMatch(psb + 1, pse, ppb, ppe, cache) || myIsMatch(psb, pse, ppb + 2, ppe, cache);
                    } else {
                        // star not match
                        match = myIsMatch(psb, pse, ppb + 2, ppe, cache);
                    }
                }
            }
        }

        cache[key] = match;
        return match;
    }

    bool myIsMatchSimple(Ptr psb, Ptr pse, Ptr ppb, Ptr ppe) {
        if (pse - psb != ppe - ppb) return false;
        if (psb == pse) return true;

        for (auto ps = psb, pp = ppb; ps != pse; ++ps, ++pp) {
            if (*ps != *pp && *pp != '.') return false;
        }

        return true;
    }
};



// use matrix as cache, offsets as cache keys

using Ptr = const char*;
using Cache = vector<vector<int>>;

class Solution {
public:
    bool isMatch(string s, string p) {
        Cache cache(s.size() + 1, vector<int>(p.size() + 1, -1));
        return myIsMatch(s.data(), s.data() + s.size(), p.data(), p.data() + p.size(), cache);
    }

private:
    bool myIsMatch(Ptr psb, Ptr pse, Ptr ppb, Ptr ppe, Cache& cache) {
        const int i = pse - psb, j = ppe - ppb;
        if (cache[i][j] != -1) return cache[i][j] != 0;

        bool match = true;

        auto itStar = std::find(ppb, ppe, '*');
        if (itStar == ppe) {
            // no star
            match = myIsMatchSimple(psb, pse, ppb, ppe);
        } else {
            int n = itStar - 1 - ppb;
            if (n) {
                if (pse - psb < n) match = false;
                else match = myIsMatchSimple(psb, psb + n, ppb, ppb + n);
            }

            if (match) {
                // move to star pattern
                psb += n;
                ppb += n;

                if (psb == pse) {
                    if (ppb == ppe) match = true;
                    else match = myIsMatch(psb, pse, ppb + 2, ppe, cache);
                } else {
                    if (*psb == *ppb || *ppb == '.') {
                        // star match
                        match = myIsMatch(psb + 1, pse, ppb, ppe, cache) || myIsMatch(psb, pse, ppb + 2, ppe, cache);
                    } else {
                        // star not match
                        match = myIsMatch(psb, pse, ppb + 2, ppe, cache);
                    }
                }
            }
        }

        cache[i][j] = match ? 1 : 0;
        return match;
    }

    bool myIsMatchSimple(Ptr psb, Ptr pse, Ptr ppb, Ptr ppe) {
        if (pse - psb != ppe - ppb) return false;
        if (psb == pse) return true;

        for (auto ps = psb, pp = ppb; ps != pse; ++ps, ++pp) {
            if (*ps != *pp && *pp != '.') return false;
        }

        return true;
    }
};
