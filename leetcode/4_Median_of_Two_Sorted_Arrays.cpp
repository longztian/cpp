class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long N = static_cast<long>(nums1.size()) + nums2.size();
        long m = getKth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), N / 2 + 1);

        if (N % 2 == 1) return m;

        return (static_cast<double>(m) + getKth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), N / 2)) / 2;
    }

private:
    int getKth(int* p1, int n1, int* p2, int n2, int k) {
        if (n1 < n2) return getKth(p2, n2, p1, n1, k);

        // n1 >= n2
        if (n2 == 0) return *(p1 + k - 1);
        if (k == 1) return min(*p1, *p2);

        int i1 = min(n1, k / 2), i2 = min(n2, k / 2);
        return (*(p1 + i1 - 1) > *(p2 + i2 - 1)) ? getKth(p1, n1, p2 + i2, n2 - i2, k - i2)
                                         : getKth(p1 + i1, n1 - i1, p2, n2, k - i1);
    }
};
