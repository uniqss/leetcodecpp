#include "../inc.h"

class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {}
};

void test(vector<vector<int>>&& grid, int expect) {
    auto grid_param = grid;
    Solution so;
    auto ret = so.equalPairs(grid);
    assert_eq_ret(expect, ret);
    print(grid_param);
}

int main() {
    test({{3, 2, 1}, {1, 7, 6}, {2, 7, 7}}, 1);
    test({{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}}, 3);
    return 0;
}
