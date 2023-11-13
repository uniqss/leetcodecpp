#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {}
};

void test(vector<vector<int>>&& heights, const vector<vector<int>>& cexpect) {
    auto expect = cexpect;
    auto p1 = heights;
    Solution so;
    auto ret = so.pacificAtlantic(heights);
    sort(expect.begin(), expect.end());
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
    print(p1);
}

int main() {
    test({{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}},
         {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}});
    test({{1}}, {{0, 0}});

    return 0;
}
