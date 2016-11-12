class Solution {
public:
    int maxArea(vector<int>& height) {
        auto pb = height.data(), pe = pb + height.size() - 1;
        int low, area, maxA = 0;

        while (pb < pe) {
            if (*pb < *pe) {
                // begin is shorter
                low = *pb;
                area = low * (pe - pb);
                while (pb < pe && *pb <= low) ++pb;
            } else {
                // end is shorter
                low = *pe;
                area = low * (pe - pb);
                while (pb < pe && *pe <= low) --pe;
            }

            if (area > maxA) maxA = area;
        }

        return maxA;
    }
};
