#include "../inc.h"

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {}
};

void test(vector<vector<int>>&& grid, int expect) {
    save4print(grid);
    auto ret = Solution().orangesRotting(grid);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4);
    test({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1);
    test({{0, 2}}, 0);
    return 0;
}
