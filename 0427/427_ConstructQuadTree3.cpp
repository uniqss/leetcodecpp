#include "../helpers/stl.h"
#include "../helpers/complexval.h"
#include "../helpers/uassert.h"
#include "../helpers/quadtreehelper.h"

// 妙啊。。。
class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        // pre[x][y]的意义：以 (x,y)为右下角，(0,0)为左上角里面所有元素的和
        vector<vector<int>> pre(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        auto sum = [&](int x0, int y0, int x1, int y1) {
            return pre[x1][y1] - pre[x1][y0] - pre[x0][y1] + pre[x0][y0];
        };
        function<Node*(int, int, int, int)> dfs = [&](int x0, int y0, int x1, int y1) {
            auto vsum = sum(x0, y0, x1, y1);
            if (vsum == 0) return new Node(0, true);
            if (vsum == (x1 - x0) * (y1 - y0)) return new Node(1, true);
            int xmid = (x0 + x1) / 2, ymid = (y0 + y1) / 2;
            return new Node(1, false, dfs(x0, y0, xmid, ymid), dfs(x0, ymid, xmid, y1), dfs(xmid, y0, x1, ymid),
                            dfs(xmid, ymid, x1, y1));
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
