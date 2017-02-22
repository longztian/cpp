/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger> &nestedList) : myList(nestedList), myIndex(0), myIter(nullptr) {

    }

    int next() {
        if (myIter) return myGetFromIterator();

        while (myIndex < myList.size()) {
            if (myList[myIndex].isInteger()) {
                int v = myList[myIndex].getInteger();
                ++myIndex;
                return v;
            }

            // list
            const auto& l = myList[myIndex].getList();
            if (!l.empty()) {
                myIter.reset(new NestedIterator(l));
                return myGetFromIterator();
            }

            ++myIndex;
        }

        return -1;

    }

    // test case [[][]]
    bool hasNext() {
        if (myIter) return true;

        while (myIndex < myList.size()) {
            if (myList[myIndex].isInteger()) return true;

            // list
            const auto& l = myList[myIndex].getList();
            if (!l.empty()) {
                myIter.reset(new NestedIterator(l));
                if (!myIter->hasNext()) {
                    myIter = nullptr;
                } else {
                    return true;
                }
            }

            ++myIndex;
        }

        return false;
    }

private:
    int myIndex;
    std::unique_ptr<NestedIterator> myIter;
    const vector<NestedInteger>& myList;

    int myGetFromIterator() {
        int v = myIter->next();
        if (!myIter->hasNext()) {
            myIter = nullptr;
            ++myIndex;
        }
        return v;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
