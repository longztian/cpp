// O(Nlog(N)) time, O(n) space

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        if (N < 2) return nums;

        auto sorted = nums;
        std::sort(sorted.begin(), sorted.end());

        for (int i = N - 1, left = 0, right = i / 2 + 1; i >= 0; --i) {
            nums[i] = sorted[i & 1 ? right++ : left++];
        }
    }
};


// O(N) time, O(N) space

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        if (N < 2) return;

        auto partitioned = nums;
        const auto ITB = partitioned.begin(), ITE = partitioned.end(), ITM = ITB + N / 2;
        std::nth_element(ITB, ITM, ITE);
        std::partition(ITB, ITM, [m = *ITM](const int v) { return v != m; });
        std::partition(ITM + 1, ITE, [m = *ITM](const int v) { return v == m; });

        for (int i = N - 1, left = 0, right = i / 2 + 1; i >= 0; --i) {
            nums[i] = partitioned[i & 1 ? right++ : left++];
        }
    }
};


// O(N) time, O(1) space

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        if (N < 2) return;

        const auto ITB = nums.begin(), ITE = nums.end();
        std::nth_element(ITB, ITB + N / 2, ITE);

        auto median = nums[N / 2];

        auto id = [N](int i) { return (i * 2 + 1) % (N | 1); };

        auto first = 0, last = N - 1, mid = 0;
        while (mid <= last) {
            if (nums[id(mid)] > median) {
                std::swap(nums[id(mid)], nums[id(first)]);
                ++first;
                ++mid;
            } else if (nums[id(mid)] < median) {
                std::swap(nums[id(mid)], nums[id(last)]);
                --last;
            } else {
                ++mid;
            }
        }
    }
};
