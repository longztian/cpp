/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

// line: y = k * x + b
// k and b are float
//
// k * (x1 - x2) = y1 - y2
// b * (x1 - x2) = x1 * y2 - x2 * y1
//
// integer parameters:
// let factor = x1 - x2
// let k = k * factor
// let b = b * factor

// for a vertical line:
// x = b
struct Line {
    long f;
    long k;
    long b;

    void setPoints(const Point& p1, const Point& p2) {
        if (p1.x == p2.x) {
            f = 0;
            k = 1;
            b = p1.x;
        } else {
            f = (long) p1.x - p2.x;
            k = (long) p1.y - p2.y;
            b = (long) p1.x * p2.y - (long) p2.x * p1.y;
        }
    }

    bool operator==(const Line& rhs) const {
        if (f != 0 && rhs.f != 0) {
            return k * rhs.f == rhs.k * f && b * rhs.f == rhs.b * f;
        } else {
            return f == rhs.f && b == rhs.b;
        }
    }
};

namespace std {
template <> struct hash<Line> {
    size_t operator()(const Line& ln) const {
        return hash<long>()(ln.f != 0 ? ln.b / ln.f : ln.b);
    }
};

template <> struct hash<Point> {
    size_t operator()(const Point& pnt) const {
        return hash<int>()(pnt.x);
    }
};

template <> struct equal_to<Point> {
    bool operator()(const Point& lhs, const Point& rhs) const {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};
}

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();

        unordered_map<Point, int> pointCounts;
        for (auto& pnt : points) pointCounts[pnt] += 1;

        const int NP = pointCounts.size();

        int n = 0;
        if (NP < 3) {
            for (auto& pc : pointCounts) n += pc.second;
            return n;
        }

        int i = 0;
        vector<const unordered_map<Point, int>::value_type*> pointCountPointers(NP);
        for (auto& pc : pointCounts) pointCountPointers[i++] = &pc;

        vector<vector<int>> visited(NP, vector<int>(NP, 0));
        unordered_map<Line, vector<int>> linePoints;
        Line ln;
        for (int i = 0; i < NP - 1; ++i) {
            linePoints.clear();
            auto& pi = *pointCountPointers[i];
            for (int j = i + 1; j < NP; ++j) {
                if (visited[i][j] == 0) {
                    ln.setPoints(pi.first, pointCountPointers[j]->first);
                    linePoints[ln].push_back(j);
                }
            }

            for (auto& lp : linePoints) {
                int count = pi.second;

                for (int m = 0; m < lp.second.size(); ++m) {
                    count += pointCountPointers[lp.second[m]]->second;

                    for (int n = m + 1; n < lp.second.size(); ++n) {
                        visited[lp.second[m]][lp.second[n]] = 1;
                    }
                }

                if (n < count) n = count;
            }
        }

        return n;
    }
};


class Solution {
public:
    int maxPoints(vector<Point> &points) {

        if(points.size()<2) return points.size();

        int result=0;

        for(int i=0; i<points.size(); i++) {

            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;

            for(int j=i+1; j<points.size(); j++) {

                if(points[j].x==points[i].x && points[j].y==points[i].y) {

                    overlap++;
                    continue;
                }
                else if(points[j].x==points[i].x) vertical++;
                else {

                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);

                    a/=gcd;
                    b/=gcd;

                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }

                localmax=max(vertical, localmax);
            }

            result=max(result, localmax+overlap+1);
        }

        return result;
    }

private:
    int GCD(int a, int b) {

        if(b==0) return a;
        else return GCD(b, a%b);
    }
};
