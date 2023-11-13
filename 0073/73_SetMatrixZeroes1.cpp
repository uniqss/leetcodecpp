#include "../inc.h"

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> zx(m), zy(n);
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (matrix[x][y] == 0) zx[x] = true, zy[y] = true;
            }
        }
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (zx[x] || zy[y]) matrix[x][y] = 0;
            }
        }
    }
};

void test(vector<vector<int>>&& matrix, const vector<vector<int>>& expect) {
    save4print(matrix);
    Solution().setZeroes(matrix);
    assert_eq_ret(expect, matrix);
}

int main() {
    test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});
    test({{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}});
    return 0;
}
