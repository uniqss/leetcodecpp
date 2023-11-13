#include "../inc.h"

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>& rhs) { return lhs[1] < rhs[1]; });
        int count = 1, end = intervals[0][1];  // no overlap count
        for (int i = 1; i < intervals.size(); ++i) {
            if (end <= intervals[i][0]) {
                ++count;
                end = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};

void test(vector<vector<int>>&& intervals, int expect) {
    auto intervals_param = intervals;
    Solution so;
    auto ret = so.eraseOverlapIntervals(intervals);
    assert_eq_ret(expect, ret);
    print(intervals_param);
}

int main() {
    test({{1, 2}, {2, 10}, {3, 11}, {4, 11}, {5, 11}}, 3);
    test({{1, 2}, {2, 3}, {3, 4}, {1, 3}}, 1);
    test({{1, 2}, {1, 2}, {1, 2}}, 2);
    test({{1, 2}, {2, 3}}, 0);
    return 0;
}
