struct Node {
    int key;
    int value;
    int freq;

    Node(int key, int value) : key(key), value(value), freq(1) {}
};

using DataList = list<Node>;
using DataMap = unordered_map<int, DataList::iterator>;

class LFUCache {
public:
    LFUCache(int capacity) : myCapacity(capacity) {}

    int get(int key) {
        auto it = myLookup.find(key);
        if (it == myLookup.end()) return -1;

        myTouch(it);
        return it->second->value;
    }

    void set(int key, int value) {
        if (myCapacity <= 0) return;

        auto it = myLookup.find(key);
        if (it == myLookup.end()) {
            if (myLookup.size() == myCapacity) {
                myLookup.erase(myData.front().key);
                myData.pop_front();
            }
            auto i = myData.begin();
            while (i != myData.end() && i->freq == 1) ++i;
            myLookup[key] = myData.insert(i, Node(key, value));

        } else {
            myTouch(it);
            it->second->value = value;
        }
    }

private:
    int myCapacity;
    DataMap myLookup;
    DataList myData;

    void myTouch(DataMap::iterator it) {
        Node n(*it->second);
        ++n.freq;
        auto i = myData.erase(it->second);
        while (i != myData.end() && i->freq <= n.freq) ++i;
        it->second = myData.insert(i, n);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */


// O(1) get() set()
struct Node {
    int key;
    int value;
    int freq;

    Node(int key, int value) : key(key), value(value), freq(1) {}
};

using DataList = list<Node>;
using DataListList = list<DataList>;
using DataMap = unordered_map<int, pair<DataListList::iterator, DataList::iterator>>;

class LFUCache {
public:
    LFUCache(int capacity) : myCapacity(capacity) {

    }

    int get(int key) {
        auto it = myLookup.find(key);
        if (it == myLookup.end()) return -1;

        myTouch(it);
        return it->second->second->value;
    }

    void set(int key, int value) {
        if (myCapacity <= 0) return;

        auto it = myLookup.find(key);
        if (it == myLookup.end()) {
            if (myLookup.size() == myCapacity) {
                myLookup.erase(myData.front().front().key);
                if (myData.front().size() == 1) myData.pop_front();
                else myData.front().pop_front();
            }
            if (myData.front().front().freq > 1) myData.push_front(NodeList());
            myLookup[key] = make_pair(myData.begin(), myData.front().insert(myData.front().end(), Node(key, value));

        } else {
            myTouch(it);
            it->second->second->value = value;
        }
    }

private:
    int myCapacity;
    DataMap myLookup;
    DataListList myData;

    void myTouch(DataMap::iterator it) {
        ++it->second->second->freq;

        auto itNext = it->second->first;
        ++itNext;

        if (it->second->first->size() == 1) {
            if (itNext->front().freq == it->second->second->freq) {
                itNext->push_back(*it->second->second);
                myData.erase(it->second->first);
                it->second = make_pair(itNext, --itNext.end());
            }
        } else {
            if (itNext->front().freq > it->second->second->freq) {
                itNext = myData.insert(NodeList());
            }
            itNext->push_back(*it->second->second)
            it->second->first->erase(it->second->second);
            it->second = make_pair(itNext, itNext.begin());
        }
        auto i = myData.erase(it->second);
        while (i != myData.end() && i->freq <= n.freq) ++i;
        it->second = myData.insert(i, n);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */
