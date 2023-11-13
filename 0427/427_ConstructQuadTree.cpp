#include "../helpers/stl.h"
#include "../helpers/complexval.h"
#include "../helpers/uassert.h"
#include "../helpers/quadtreehelper.h"

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {}
};

void test(vector<vector<int>>&& grid, const vector<ComplexVal>& expect) {
    save4print(grid);
    Node* ret = Solution().construct(grid);
    QuadTreeAutoReleaser _(ret);
    assert_eq_ret(expect, quadtree_node2vals(ret));
}

int main() {
    test({{0, 1}, {1, 0}}, {{0, 1}, {1, 0}, {1, 1}, {1, 1}, {1, 0}});
    test({{1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0}},
         {{0, 1}, {1, 1}, {0, 1}, {1, 1}, {1, 0}, null, null, null, null, {1, 0}, {1, 0}, {1, 1}, {1, 1}});
    return 0;
}
