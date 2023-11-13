#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {}
};

void test(vector<vector<int>>&& intervals, vector<int>&& newInterval, const vector<vector<int>>& expect) {
    save4print(intervals);
    save4print(newInterval);
    Solution so;
    auto ret = so.insert(intervals, newInterval);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{3, 5}, {12, 15}}, {6, 6}, {{3, 5}, {6, 6}, {12, 15}});
    test({{1, 5}}, {0, 3}, {{0, 5}});
    test({{1, 3}, {6, 9}}, {2, 5}, {{1, 5}, {6, 9}});
    test({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}, {{1, 2}, {3, 10}, {12, 16}});
    return 0;
}
