#include "../inc.h"

/*
先以前数从小大到排序，后面的
本质 上是三种情况：
    1.无交（第一次时返回结构空归并到这一类中）
    2.交而不吃----两头冒尖
    3.吃----完全被前一个吃掉
*/
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; });
        vector<vector<int>> ret;
        int maxreached = 0;
        for (const auto& curr : intervals) {
            if (ret.empty() || curr[0] > maxreached) {
                maxreached = max(maxreached, curr[1]);
                ret.emplace_back(curr);
            } else {
                maxreached = max(maxreached, curr[1]);
                ret.back()[1] = max(maxreached, ret.back()[1]);
            }
        }
        return ret;
    }
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
