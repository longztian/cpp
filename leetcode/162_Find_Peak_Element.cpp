class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        return myFindPeak(nums, 0, nums.size() - 1);
    }

private:
    int myFindPeak(const vector<int>& nums, const int IB, const int IE) {
        const int N = IE - IB;
        if (N == 0) return IB;
        if (N == 1) return nums[IB] > nums[IE] ? IB : IE;

        const int IM = IB + N / 2;
        if (nums[IM] < nums[IM - 1]) return myFindPeak(nums, IB, IM - 1);
        else if (nums[IM] < nums[IM + 1]) return myFindPeak(nums, IM + 1, IE);
        else return IM;
    }
};
