class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        if (k <= 0) return res;

        res.reserve(k);

        myMax(nums1.data(), nums1.data() + nums1.size(), nums2.data(), nums2.data() + nums2.size(), k, res);

        return res;
    }

private:
    void myMax(int* pb1, int* pe1, int* pb2, int* pe2, int k, vector<int>& res) {
        if (k <= 0) return;

        size_t n = (pe1 - pb1) + (pe2 - pb2) - k;
        auto p1Max = pe1, p2Max = pe2;
        if (pb1 < pe1) {
            p1Max = max_element(pb1, min(pe1, pb1 + n + 1));
        } else {
            myMax(pb2, pe2, k, res);
            return;
        }

        if (pb2 < pe2) {
            p2Max = max_element(pb2, min(pe2, pb2 + n + 1));
        } else {
            myMax(pb1, pe1, k, res);
            return;
        }

        if (*p1Max > *p2Max) {
            res.push_back(*p1Max);
            myMax(p1Max + 1, pe1, pb2, pe2, k - 1, res);
        } else if (*p1Max < *p2Max) {
            res.push_back(*p2Max);
            myMax(pb1, pe1, p2Max + 1, pe2, k - 1, res);
        } else {
            auto res1 = res;
            res1.push_back(*p1Max);
            myMax(p1Max + 1, pe1, pb2, pe2, k - 1, res1);

            auto res2 = res;
            res2.push_back(*p2Max);
            myMax(pb1, pe1, p2Max + 1, pe2, k - 1, res2);

            res = max(res1, res2);
        }
    }

    void myMax(int* pb, int* pe, int k, vector<int>& res) {
        if (k <= 0) return;
        size_t n = (pe -pb) - k;
        auto pMax = max_element(pb, pb + n + 1);
        res.push_back(*pMax);
        myMax(pMax + 1, pe, k - 1, res);
    }
};


// wrong solution
/**
 * Your input
 * [3,4,6,5]
 * [9,1,2,5,8,3]
 * 5
 * Your answer
 * [9,8,6,5,5]
 * Expected answer
 * [9,8,6,5,3]
 */

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        if (k <= 0) return ret;

        ret.reserve(k);

        const auto P1 = nums1.data(), P2 = nums2.data();
        int n1 = nums1.size(), n2 = nums2.size();
        nth_element(P1, P1 + n1 - 1, P1 + n1);
        nth_element(P2, P2 + n2 - 1, P2 + n2);

        while (n1 && n2 && k) {
            if (nums1.back() > nums2.back()) {
                ret.push_back(nums1.back());
                nums1.pop_back();
                --n1;
                if (n1 > 1) nth_element(P1, P1 + n1 - 1, P1 + n1);
            } else {
                ret.push_back(nums2.back());
                nums2.pop_back();
                --n2;
                if (n2 > 1) nth_element(P2, P2 + n2 - 1, P2 + n2);
            }
            --k;
        }

        if (k > 0) {
            if (n1) {
                while (k--) {
                    ret.push_back(nums1.back());
                    nums1.pop_back();
                    --n1;
                    nth_element(P1, P1 + n1 - 1, P1 + n1);
                }
            } else {
                while (k--) {
                    ret.push_back(nums2.back());
                    nums2.pop_back();
                    --n2;
                    nth_element(P2, P2 + n2 - 1, P2 + n2);
                }
            }
        }

        return ret;
    }
};
