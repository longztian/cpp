class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        // myData.push_back(num);
        myData.insert(std::lower_bound(myData.begin(), myData.end(), num), num);
    }

    double findMedian() {
        if (myData.empty()) return 0;

        // std::sort(myData.begin(), myData.end());

        int m = myData.size() / 2;
        if (myData.size() % 2) {
            return myData[m];
        } else {
            return myData[m] + static_cast<double>(myData[m - 1] - myData[m]) / 2;
        }
    }

private:
    std::vector<int> myData;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
