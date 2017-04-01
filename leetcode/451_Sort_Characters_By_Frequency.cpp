class Solution {
public:
    string frequencySort(string s) {
        constexpr size_t NCHAR = 256;
        array<size_t, NCHAR> counts;
        fill(counts.begin(), counts.end(), 0);

        for (auto c : s) {
            ++counts[c];
        }

        map<size_t, vector<char>> countCharsMap;
        for (size_t i = 0; i < NCHAR; ++i) {
            if (counts[i] > 0) countCharsMap[counts[i]].push_back(i);
        }

        string ret;
        for (auto it = countCharsMap.rbegin(), ite = countCharsMap.rend(); it != ite; ++it) {
            for (auto c : it->second) {
                ret.append(it->first, c);
            }
        }

        return ret;
    }
};
