class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;

        auto l = height.begin(), r = height.end() - 1;
        int water = 0, level = 0, h = 0;
        while (l < r) {
            h = *l < *r ? *l++ : *r--;
            if (h < level) water += level - h;
            else level = h;
        }

        return water;
    }
};
