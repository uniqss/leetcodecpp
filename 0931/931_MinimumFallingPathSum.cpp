#include "../inc.h"

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {}
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
