class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (myValueIndexMap.find(val) != myValueIndexMap.end()) return false;

        myValueIndexMap.emplace(val, myData.size());
        myData.push_back(val);

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = myValueIndexMap.find(val);
        if (it == myValueIndexMap.end()) return false;

        if (it->second != myData.size() - 1) {
            myValueIndexMap[myData.back()] = it->second;
            std::swap(myData[it->second], myData.back());
        }

        myValueIndexMap.erase(it);
        myData.pop_back();

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return myData[rand() % myData.size()];
    }

private:
    std::vector<int> myData;
    std::unordered_map<int, int> myValueIndexMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
