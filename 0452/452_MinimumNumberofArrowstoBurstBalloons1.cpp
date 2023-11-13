#include "../inc.h"

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& lhs, vector<int>& rhs) { return lhs[1] < rhs[1]; });
        int end = points[0][1], arrcount = 1;
        for (int i = 1; i < points.size(); ++i) {
            // 这里比较特殊，== 的时候，不需要重新发射一支箭，想象为气球是有一定厚度的，擦皮就破
            if (end < points[i][0]) {
                ++arrcount;
                end = points[i][1];
            } else {
                // don't need a new arrow
            }
        }
        return arrcount;
    }
};

void test(vector<vector<int>>&& points, int expect) {
    auto p1 = points;
    Solution so;
    auto ret = so.findMinArrowShots(points);
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({{-2147483648, 2147483647}}, 1);
    test({{10, 16}, {2, 8}, {1, 6}, {7, 12}}, 2);
    test({{1, 2}, {3, 4}, {5, 6}, {7, 8}}, 4);
    test({{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 2);
    return 0;
}
