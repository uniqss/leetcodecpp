#include "../inc.h"

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), remain = 0, ret = 0;
        vector<pair<int, int>> bad;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    ++remain;
                else if (grid[i][j] == 2)
                    bad.emplace_back(i, j);
            }
        }
        auto bstart = 0;
        while (remain > 0) {
            auto bsize = bad.size();
            for (int bi = bstart; bi < bsize; ++bi) {
                auto [i, j] = bad[bi];
                checkrot(i + 1, j, bad, grid, remain);
                checkrot(i - 1, j, bad, grid, remain);
                checkrot(i, j + 1, bad, grid, remain);
                checkrot(i, j - 1, bad, grid, remain);
            }

            if (bsize == bad.size()) break;
            bstart = bsize - 1;
            ++ret;
        }
        return remain > 0 ? -1 : ret;
    }
    void checkrot(int i, int j, vector<pair<int, int>>& bad, vector<vector<int>>& grid,
                  int& remain) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            bad.emplace_back(i, j);
            --remain;
        }
    }
};

void test(vector<vector<int>>&& grid, int expect) {
    save4print(grid);
    assert_eq_ret(expect, Solution().orangesRotting(grid));
}

int main() {
    test({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4);
    test({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1);
    test({{0, 2}}, 0);
    return 0;
}
