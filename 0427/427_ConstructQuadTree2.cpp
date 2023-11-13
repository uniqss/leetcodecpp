#include "../helpers/stl.h"
#include "../helpers/complexval.h"
#include "../helpers/uassert.h"
#include "../helpers/quadtreehelper.h"

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int, int, int, int)> dfs = [&](int x0, int y0, int x1, int y1) {
            for (int x = x0; x < x1; ++x) {
                for (int y = y0; y < y1; ++y) {
                    if (grid[x][y] != grid[x0][y0]) {
                        return new Node(1, false, dfs(x0, y0, (x0 + x1) / 2, (y0 + y1) / 2),
                                        dfs(x0, (y0 + y1) / 2, (x0 + x1) / 2, y1),
                                        dfs((x0 + x1) / 2, y0, x1, (y0 + y1) / 2),
                                        dfs((x0 + x1) / 2, (y0 + y1) / 2, x1, y1));
                    }
                }
            }
            return new Node(grid[x0][y0], true);
        };
        return dfs(0, 0, grid.size(), grid.size());
    }
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
