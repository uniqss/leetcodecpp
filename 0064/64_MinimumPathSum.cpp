#include "../inc.h"

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {}
};

void test(vector<vector<int>>&& grid, int expect) {
    save4print(grid);
    assert_eq_ret(expect, Solution().minPathSum(grid));
}

int main() {
    test({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7);
    test({{1, 2, 3}, {4, 5, 6}}, 12);
    return 0;
}
