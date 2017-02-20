namespace {
struct PointT {
    int x;
    int y;
    PointT(int x, int y) : x(x), y(y) {};
};
}

namespace std {
template <> struct hash<PointT> {
    size_t operator()(const PointT& pnt) const {
        return hash<int>()(pnt.x + pnt.y);
    }
};

template <> struct equal_to<PointT> {
    bool operator()(const PointT& lhs, const PointT& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};
}

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> all = myGetRectangle(rectangles);
        vector<PointT> corners = {
            PointT(all[0], all[1]),
            PointT(all[0], all[3]),
            PointT(all[2], all[1]),
            PointT(all[2], all[3])
        };

        // check point counts
        unordered_map<PointT, int> pointCounts;
        for (const auto& r : rectangles) {
            ++pointCounts[PointT(r[0], r[1])];
            ++pointCounts[PointT(r[0], r[3])];
            ++pointCounts[PointT(r[2], r[1])];
            ++pointCounts[PointT(r[2], r[3])];
        }
        for (const auto& p : corners) {
            if (pointCounts[p] != 1) return false;
            pointCounts.erase(p);
        }
        for (const auto& v : pointCounts) {
            if (v.second != 2 && v.second != 4) return false;
        }

        // check area
        long area = 0;
        for (const auto& rec : rectangles) area += myArea(rec);
        if (area != myArea(all)) return false;

        return true;

    }

private:
    vector<int> myGetRectangle(const vector<vector<int>>& rectangles) {
        vector<int> ret = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
        for (const auto& rec : rectangles) {
            for (int i = 0; i < 2; ++i) if (ret[i] > rec[i]) ret[i] = rec[i];
            for (int i = 2; i < 4; ++i) if (ret[i] < rec[i]) ret[i] = rec[i];
        }
        return ret;
    }

    long myArea(const vector<int>& rec) {
        return (static_cast<long>(rec[2]) - rec[0]) * (static_cast<long>(rec[3]) - rec[1]);
    }
};
