class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;

        map<int, pair<int, int>> heightIndexes;
        for (int i = 0; i < height.size(); ++i) {
            auto it = heightIndexes.find(height[i]);
            if (it == heightIndexes.end()) {
                heightIndexes.insert({height[i], {i, i}});
            } else {
                it->second.second = i;
            }
        }

        auto it = heightIndexes.rbegin();
        int left = it->second.first, right = it->second.second;

        int water = 0;
        if (left + 1 < right) {
            // water between top peaks?
            water += myGetWater(left + 1, right, it->first, height);
        }

        while (++it != heightIndexes.rend()) {
            // left side
            if (left > it->second.first) {
                if (it->second.first + 1 < left) water += myGetWater(it->second.first + 1, left, it->first, height);
                left = it->second.first;
            }

            // right side
            if (right < it->second.second) {
                if (right + 1 < it->second.second) water += myGetWater(right + 1, it->second.second, it->first, height);
                right = it->second.second;
            }
        }

        return water;
    }

private:
    int myGetWater(int begin, int end, int low, const vector<int>& height) {
        int nblocks = 0;
        for (int i = begin; i < end; ++i) {
            nblocks += height[i];
        }
        return (end - begin) * low - nblocks;
    }
};
