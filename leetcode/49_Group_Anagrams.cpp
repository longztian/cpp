class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> keyIndexMap;
        vector<vector<string>> ret;

        auto it = keyIndexMap.end();
        string key;
        for (auto& s : strs) {
            mySort(s, key);
            it = keyIndexMap.find(key);
            if (it == keyIndexMap.end()) {
                ret.emplace_back(1, s);
                keyIndexMap.emplace(key, ret.size() - 1);
            } else {
                ret[it->second].emplace_back(s);
            }
        }

        return ret;
    }

private:
    void mySort(string input, string& ordered) {
        std::sort(input.begin(), input.end());
        std::swap(input, ordered);
    }
};
