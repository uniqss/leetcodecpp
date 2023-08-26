#include "../inc.h"

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 这样解有点糙，有优化空间，可以把unordered_map拿掉，grid直接判1改2
        int m = grid.size(), n = grid[0].size();
        auto transxy = [](int x, int y) { return x * 11 + y; };
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        int remain = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    ++remain;
                else if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    visited.insert(transxy(i, j));
                } else {
                    visited.insert(transxy(i, j));
                }
            }
        }
        int level = 0;
        while (!q.empty() && remain > 0) {
            auto qsize = q.size();
            for (size_t i = 0; i < qsize; ++i) {
                auto [x, y] = q.front();
                q.pop();
                if (x > 0 && visited.count(transxy(x - 1, y)) == 0 && grid[x - 1][y] == 1) {
                    --remain;
                    visited.insert(transxy(x - 1, y));
                    q.emplace(x - 1, y);
                }
                if (x < m - 1 && visited.count(transxy(x + 1, y)) == 0 && grid[x + 1][y] == 1) {
                    --remain;
                    visited.insert(transxy(x + 1, y));
                    q.emplace(x + 1, y);
                }
                if (y > 0 && visited.count(transxy(x, y - 1)) == 0 && grid[x][y - 1] == 1) {
                    --remain;
                    visited.insert(transxy(x, y - 1));
                    q.emplace(x, y - 1);
                }
                if (y < n - 1 && visited.count(transxy(x, y + 1)) == 0 && grid[x][y + 1] == 1) {
                    --remain;
                    visited.insert(transxy(x, y + 1));
                    q.emplace(x, y + 1);
                }
            }
            ++level;
        }

        return remain == 0 ? level : -1;
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
