#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {}
};

void test(vector<vector<int>>&& intervals, const vector<vector<int>>& expect) {
    save4print(intervals);
    Solution so;
    auto ret = so.merge(intervals);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}});
    test({{1, 4}, {4, 5}}, {{1, 5}});
    return 0;
}
