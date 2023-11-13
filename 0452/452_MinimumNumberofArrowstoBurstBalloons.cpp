#include "../inc.h"

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {}
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
