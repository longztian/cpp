class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < 2 || k == 1) return nums;

        const int N = nums.size() - k + 1;
        vector<int> ret(N, INT_MIN);

        auto p = nums.data();
        int max = *std::max_element(p, p + k);
        ret[0] = max;
        for (int i = 1; i < N; ++i, ++p) {
            if (*(p + k) >= max) {
                max = *(p + k);
            } else if (*p == max) {
                max = *std::max_element(p + 1, p + k + 1);
            }

            ret[i] = max;
        }

        return ret;
    }
};



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < 2 || k == 1) return nums;

        deque<int> q;

        int i = 0;
        for (; i < k; ++i) {
            myPush(q, nums, i);
        }

        const int N = nums.size();
        vector<int> ret(N - k + 1);
        ret[0] = nums[q.front()];

        for (int j = 1; i < N; ++i, ++j) {
            if (q.front() == i - k) q.pop_front();
            myPush(q, nums, i);
            ret[j] = nums[q.front()];
        }

        return ret;
    }

private:
    inline void myPush(deque<int>& q, const vector<int>& nums, const int i) {
        while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
        q.push_back(i);
    }
};
