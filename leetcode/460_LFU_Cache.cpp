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

    Node(int key, int value) : key(key), value(value) {}
};

struct Frequency {
    int freq;
    list<Node> nodes;

    Frequency() : freq(1) {}
    Frequency(int freq) : freq(freq) {}
};

using DataList = list<Node>;
using FreqList = list<Frequency>;
using DataMap = unordered_map<int, pair<FreqList::iterator, DataList::iterator>>;

class LFUCache {
public:
    LFUCache(int capacity) : myCapacity(capacity) {}

    int get(int key) {
        auto it = myLookup.find(key);
        if (it == myLookup.end()) return -1;

        myTouch(it);
        return it->second.second->value;
    }

    void set(int key, int value) {
        if (myCapacity <= 0) return;

        auto it = myLookup.find(key);
        if (it == myLookup.end()) {
            if (myLookup.size() == myCapacity) {
                myLookup.erase(myData.front().nodes.front().key);
                if (myData.front().nodes.size() == 1) myData.pop_front();
                else myData.front().nodes.pop_front();
            }
            if (myData.empty() || myData.front().freq > 1) myData.push_front(Frequency(1));
            myData.front().nodes.emplace_back(key, value);
            myLookup[key] = make_pair(myData.begin(), --myData.front().nodes.end());
        } else {
            myTouch(it);
            it->second.second->value = value;
        }
    }

private:
    int myCapacity;
    DataMap myLookup;
    FreqList myData;

    void myTouch(const DataMap::iterator it) {
        auto itNode = it->second.second;
        auto itFreq = it->second.first, itFreqNext = itFreq;
        ++itFreqNext;

        if (itFreqNext == myData.end() || itFreqNext->freq > itFreq->freq + 1) {
            itFreqNext = myData.insert(itFreqNext, Frequency(itFreq->freq + 1));
        }

        it->second.second = itFreqNext->nodes.insert(itFreqNext->nodes.end(), *itNode);

        if (itFreq->nodes.size() == 1) {
            myData.erase(itFreq);
        } else {
            itFreq->nodes.erase(itNode);
        }

        it->second.first = itFreqNext;
    }
};
