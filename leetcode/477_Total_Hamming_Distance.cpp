/*
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for (int i = 0, n = nums.size(); i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                total += myHammingDistance(nums[i], nums[j]);
            }
        }

        return total;
    }

private:
    int myHammingDistance(int n1, int n2) {
        int n = n1 ^ n2;
        int dist = 0;
        while (n) {
            dist += n % 2;
            n >>= 1;
        }
        return dist;
    }
};
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size(), bitCount;
        for (int i = 0; i < 32; ++i) {
            bitCount = 0;
            for (int j = 0; j < n; ++j) {
                bitCount += (nums[j] >> i) & 1;
            }
            total += bitCount * (n - bitCount);
        }

        return total;
    }
};
