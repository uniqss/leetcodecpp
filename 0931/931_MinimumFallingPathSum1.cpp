#include "../inc.h"

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        int ret = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ret = min(ret, matrix[0][i]);
        }
        for (int row = 1; row < n; ++row) {
            ret = INT_MAX;
            for (int col = 0; col < n; ++col) {
                int vup = matrix[row - 1][col];
                if (col > 0) vup = min(vup, matrix[row - 1][col - 1]);
                if (col < n - 1) vup = min(vup, matrix[row - 1][col + 1]);
                matrix[row][col] += vup;
                ret = min(ret, matrix[row][col]);
            }
        }

        return ret;
    }
};

void test(vector<vector<int>>&& matrix, int expect) {
    auto matrix_param = matrix;
    Solution so;
    auto ret = so.minFallingPathSum(matrix);
    assert_eq_ret(expect, ret);
    print(matrix_param);
}

int main() {
    test({{2, 1, 3}, {6, 5, 4}, {7, 8, 9}}, 13);
    test({{-19, 57}, {-40, -5}}, -59);
    return 0;
}
