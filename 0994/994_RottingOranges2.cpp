#include "../inc.h"

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0, remain = 0;
        queue<pair<int, int>> bad;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    ++remain;
                else if (grid[i][j] == 2) {
                    bad.emplace(i, j);
                }
            }
        }
        while (remain > 0 && !bad.empty()) {
            auto qsize = bad.size();
            bool newbad = false;
            for (size_t qi = 0; qi < qsize; qi++) {
                auto [x, y] = bad.front();
                bad.pop();
                if (x > 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    bad.emplace(x - 1, y);
                    --remain;
                    newbad = true;
                }
                if (x < m - 1 && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    bad.emplace(x + 1, y);
                    --remain;
                    newbad = true;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    bad.emplace(x, y - 1);
                    --remain;
                    newbad = true;
                }
                if (y < n - 1 && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    bad.emplace(x, y + 1);
                    --remain;
                    newbad = true;
                }
            }
            if (!newbad) break;
            ++ret;
        }

        return remain > 0 ? -1 : ret;
    }
};

void test(vector<vector<int>>&& grid, int expect) {
    auto g_param = grid;
    Solution so;
    auto ret = so.orangesRotting(grid);
    assert_eq_ret(expect, ret);
    print(g_param);
}

int main() {
    test({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4);
    test({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1);
    test({{0, 2}}, 0);
    return 0;
}
