#include "../inc.h"

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {}
};

void test(vector<vector<char>>&& grid, int expect) {
    save4print(grid);
    Solution so;
    auto ret = so.numIslands(grid);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{'0', '1', '0'}, {'1', '0', '1'}, {'0', '1', '0'}}, 4);
    test({{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}},
         1);
    test({{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}},
         3);
    return 0;
}
