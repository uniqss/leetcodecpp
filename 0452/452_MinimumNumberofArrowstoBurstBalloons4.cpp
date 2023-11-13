#include "../inc.h"

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; });
        int ret = 1, n = points.size(), minreachable = points[0][1];
        for (int i = 1; i < n; ++i) {
            const auto& p = points[i];
            if (p[0] <= minreachable) {
                minreachable = min(minreachable, p[1]);
            } else {
                minreachable = p[1];
                ++ret;
            }
        }
        return ret;
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
