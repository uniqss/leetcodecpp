#include "../inc.h"

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& lhs, vector<int>& rhs) { return lhs[0] < rhs[0]; });
        int end = points[0][1], saved_arrorw = 0;  // combo saved arrow
        for (int i = 1; i < points.size(); ++i) {
            if (end < points[i][0]) {
                end = points[i][1];
            } else {
                ++saved_arrorw;
                // shot in the min(points[i - 1][1], points[i][1]), to make sure the most left ballom hit.
                end = min(end, points[i][1]);
            }
        }
        // if no arrow saved, we shoot points.size() arrows. we saved saved_arrow arrows.
        return points.size() - saved_arrorw;
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
