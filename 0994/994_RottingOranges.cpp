#include "../inc.h"

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {}
};

void test(vector<vector<int>>&& grid, int expect) {
    auto g_param = grid;
    Solution so;
    auto ret = so.orangesRotting(grid);
    assert_eq_ret(expect, ret);
    print(g_param);
}

int main() {
    test({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4);
    test({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1);
    test({{0, 2}}, 0);
    return 0;
}
