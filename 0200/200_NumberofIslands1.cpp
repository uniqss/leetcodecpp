#include "../inc.h"

struct SimplePairHasher {
    size_t operator()(const std::pair<int, int>& pv) const { return std::hash<int64_t>()((((int64_t)pv.first) << 32) | (int64_t)pv.second); }
};
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0;
        unordered_set<pair<int, int>, SimplePairHasher> vis;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && vis.count({i, j}) == 0) {
                    if (dfs(grid, m, n, i, j, vis)) ++ret;
                }
            }
        }
        return ret;
    }
    bool dfs(const vector<vector<char>>& grid, int m, int n, int x, int y, unordered_set<pair<int,int>, SimplePairHasher>& vis) {
        if (x < 0 || x >= m) return false;
        if (y < 0 || y >= n) return false;
        if (vis.count({x, y}) > 0) return false;
        if (grid[x][y] != '1') return false;
        vis.emplace(x, y);
        dfs(grid, m, n, x + 1, y, vis);
        dfs(grid, m, n, x - 1, y, vis);
        dfs(grid, m, n, x, y + 1, vis);
        dfs(grid, m, n, x, y - 1, vis);
        return true;
    }
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
