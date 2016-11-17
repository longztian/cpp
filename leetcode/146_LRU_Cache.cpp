using KeyValueList = list<pair<int, int>>;

class LRUCache{
public:
    LRUCache(int capacity) : myCapacity(capacity) {}

    int get(int key) {
        auto it = myLookup.find(key);
        if (it != myLookup.end()) {
            myData.emplace_back(it->second->first, it->second->second);
            myData.erase(it->second);
            it->second = (--myData.end());
            return it->second->second;
        }

        return -1;
    }

    void set(int key, int value) {
        auto it = myLookup.find(key);
        if (it != myLookup.end()) {
            // update existing key
            myData.emplace_back(it->second->first, value);
            myData.erase(it->second);
            it->second = (--myData.end());
        } else {
            // add new key
            if (myLookup.size() == myCapacity) {
                myLookup.erase(myData.front().first);
                myData.pop_front();
            }

            myData.emplace_back(key, value);
            myLookup.emplace(key, (--myData.end()));
        }
    }

private:
    int myCapacity;
    KeyValueList myData;
    unordered_map<int, KeyValueList::iterator> myLookup;
};
