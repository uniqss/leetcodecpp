#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <limits.h>
using std::cout;
using std::endl;

struct Point2d {
    int x;
    int y;
};
struct Point2dHasher {
    size_t operator()(const Point2d& p) const { return std::hash<int>()(p.x) + std::hash<int>()(p.y); }
};
bool operator==(const Point2d& lhs, const Point2d& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
struct Map {
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    std::unordered_map<Point2d, int, Point2dHasher> pointValues;
    void RecalcXYMinMax() {
        xmin = INT_MAX;
        ymin = INT_MAX;
        xmax = INT_MIN;
        ymax = INT_MIN;
        for (auto [pt, val] : pointValues) {
            xmin = std::min(xmin, pt.x);
            ymin = std::min(ymin, pt.y);
            xmax = std::max(xmax, pt.x);
            ymax = std::max(ymax, pt.y);
        }
    }
};
class Solution {
   public:
    void GetDropGridPos(Point2d& retPos, const Map& map, const Point2d center, int range, int vmin, int vmax) {
        int xmin = center.x - 1, xmax = center.x + 1, ymin = center.y - 1, ymax = center.y + 1;
        int x = 0, y = 0;
        auto pointValid = [map, &retPos, vmin, vmax](int x, int y) {
            if (x < map.xmin || x > map.xmax || y < map.ymin || y > map.ymax) return false;
            auto it = map.pointValues.find({x, y});
            if (it == map.pointValues.end()) return false;
            int val = it->second;
            if (val >= vmin && val <= vmax) {
                retPos = {x, y};
                return true;
            }
            return false;
        };
        for (int i = 0; i < range; ++i) {
            x = xmin, y = ymin;
            for (y = ymin; y < ymax; ++y)
                if (pointValid(x, y)) return;
            for (x = xmin; x < xmax; ++x)
                if (pointValid(x, y)) return;
            for (y = ymax; y > ymin; --y)
                if (pointValid(x, y)) return;
            for (x = xmax; x > xmin; --x)
                if (pointValid(x, y)) return;
            --xmin, --ymin, ++xmax, ++ymax;
        }

        retPos = {-1, -1};
    }
};

void test(const Map& map, const Point2d& center, int range, int vmin, int vmax, const Point2d& expect) {
    Solution so;
    Point2d ret{-1, -1};
    so.GetDropGridPos(ret, map, center, range, vmin, vmax);
    if (expect == ret) {
        cout << "ok." << endl;
    } else {
        cout << "not ok." << endl;
        cout << "expect:" << expect.x << "|" << expect.y << endl;
        cout << "ret:" << ret.x << "|" << ret.y << endl;
    }
}

int main() {
    Map map;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            map.pointValues[{i, j}] = 5;
        }
    }
    // map.pointValues[{1, 1}] = 1;
    map.pointValues[{1, 2}] = 4;
    // map.pointValues[{1, 3}] = 5;
    map.pointValues[{2, 4}] = 4;
    // map.pointValues[{1, 5}] = 5;
    map.RecalcXYMinMax();

    test(map, {3, 3}, 4, 2, 4, {1, 2});
    test(map, {3, 3}, 4, 6, 8, {-1, -1});

    return 0;
}
