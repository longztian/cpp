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

        if (isAllStar(ppb, ppe)) {
            match = true;
        } else {
            auto it = std::find(ppb, ppe, '*');
            if (it == ppe) {
                // no star
                match = myIsMatchSimple(psb, pse, ppb, ppe);
            } else {
                int n = it - ppb;
                if (n) match = (pse - psb >= n && myIsMatchSimple(psb, psb + n, ppb, ppb + n));

                if (match) {
                    // move to star
                    psb += n;
                    ppb += n;

                    if (psb == pse) match = isAllStar(ppb, ppe);
                    else match = myIsMatch(psb + 1, pse, ppb, ppe, cache) || myIsMatch(psb, pse, ppb + 1, ppe, cache);
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
            if (*ps != *pp && *pp != '?') return false;
        }

        return true;
    }

    bool isAllStar(Ptr ppb, Ptr ppe) {
        return ppb < ppe && std::find_if(ppb, ppe, [](const char c) { return c != '*'; }) == ppe;
    }
};
