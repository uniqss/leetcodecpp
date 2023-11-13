#include "../inc.h"

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; ++i) grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; ++j) grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
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
