class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int N = words.size();

        vector<vector<int>> ret;
        if (N < 2) return ret;

        vector<string> rwords = words;
        for (auto& w : rwords) reverse(w.begin(), w.end());

        unordered_map<string, int> wordMap, rwordMap;
        for (int i = 0; i < N; ++i) {
            wordMap.emplace(words[i], i);
            rwordMap.emplace(rwords[i], i);
        }

        const auto ITE = wordMap.end(), ITRE = rwordMap.end();
        auto it = ITE;
        for (int i = 0; i < N; ++i) {
            for (auto PB = words[i].data(), PE = PB + words[i].size(), p = PB; p <= PE; ++p) {
                it = rwordMap.find(string(PB, p));
                if (it != ITRE && i != it->second && myIsPalindrome(p, PE)) ret.push_back(vector<int>({i, it->second}));
            }

            for (auto PB = rwords[i].data(), PE = PB + rwords[i].size(), p = PB; p <= PE; ++p) {
                it = wordMap.find(string(PB, p));
                if (it != ITE && i != it->second && myIsPalindrome(p, PE)) ret.push_back(vector<int>({it->second, i}));
            }
        }

        sort(ret.begin(), ret.end());
        auto ite = unique(ret.begin(), ret.end());
        ret.resize(distance(ret.begin(), ite));

        return ret;
    }

private:
    bool myIsPalindrome(const char* pb, const char* pe) {
        while (pe - pb > 1) {
            --pe;
            if (*pb != *pe) return false;
            ++pb;
        }
        return true;
    }
};
