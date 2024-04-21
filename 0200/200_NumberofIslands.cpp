#include "../inc.h"

/*
time complexity: O(mn)
space complexity: O(1)
*/
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0, m = grid.size(), n = grid[0].size();
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (grid[i][j] != '1') return;
            grid[i][j] = '2';
            dfs(i - 1, j);
            dfs(i, j - 1);
            dfs(i + 1, j);
            dfs(i, j + 1);
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++ret;
                    dfs(i, j);
                }
            }
        }
        return ret;
    }
};

void test(vector<vector<char>>&& grid, int expect) {
    save4print(grid);
    assert_eq_ret(expect, Solution().numIslands(grid));
}

int main() {
    test({{'0', '1', '0'}, {'1', '0', '1'}, {'0', '1', '0'}}, 4);
    test({{'1', '1', '1', '1', '0'},
          {'1', '1', '0', '1', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '0', '0', '0'}},
         1);
    test({{'1', '1', '0', '0', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '1', '0', '0'},
          {'0', '0', '0', '1', '1'}},
         3);
    return 0;
}
