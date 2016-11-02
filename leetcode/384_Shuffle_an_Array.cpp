class Solution {
public:
    Solution(vector<int> nums) {
        myNums = nums;
        myRand = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return myNums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < myRand.size(); ++i) {
            swap(myRand[i], myRand[rand() % myRand.size()]);
        }
        return myRand;
    }

private:
    vector<int> myNums;
    vector<int> myRand;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
