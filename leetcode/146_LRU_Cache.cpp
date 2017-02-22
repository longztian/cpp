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

    void put(int key, int value) {
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


/**
 * no memory allocation on new cache nodes
 */

class LRUCache {
public:
    LRUCache(int capacity) : myCapacity(capacity), myData(capacity > 0 ? capacity : 0, {0, 0}) {

    }

    int get(int key) {
        if (myCapacity <= 0) return -1;

        auto it = myLookup.find(key);
        if (it != myLookup.end()) {
            myMoveBack(it->second);

            return it->second->second;
        }

        return -1;
    }

    void put(int key, int value) {
        if (myCapacity <= 0) return;

        auto it = myLookup.find(key);
        if (it != myLookup.end()) {
            // update existing
            it->second->second = value;

            myMoveBack(it->second);
        } else {
            // create new cache
            if (myLookup.size() == myCapacity) {
                // erase least recent
                myLookup.erase(myData.front().first);
            }

            // reuse least recent node, no new node construction
            myData.front() = {key, value};
            myLookup.emplace(key, myData.begin());

            myMoveBack(myData.begin());
        }
    }

private:
    using KVList = std::list<std::pair<int, int>>;

    int myCapacity;
    KVList myData;
    std::unordered_map<int, KVList::iterator> myLookup;

    inline void myMoveBack(KVList::iterator it) {
        myData.splice(myData.end(), myData, it);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
