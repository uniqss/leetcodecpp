#include "../inc.h"

class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int ret = 0, n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool same = true;
                for (int k = 0; k < n; ++k) {
                    if (grid[i][k] != grid[k][j]) {
                        same = false;
                        break;
                    }
                }
                if (same) ++ret;
            }
        }

        return ret;
    }
};

void test(vector<vector<int>>&& grid, int expect) {
    save4print(grid);
    assert_eq_ret(expect, Solution().equalPairs(grid));
}

int main() {
    test({{3, 2, 1}, {1, 7, 6}, {2, 7, 7}}, 1);
    test({{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}}, 3);
    return 0;
}
