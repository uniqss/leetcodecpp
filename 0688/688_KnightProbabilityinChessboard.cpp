#include "../inc.h"

class Solution {
   public:
    double knightProbability(int n, int k, int row, int column) {}
};

void test(int n, int k, int row, int column, double expect) {
    Solution so;
    auto ret = so.knightProbability(n, k, row, column);
    assert_eq_ret(expect, ret);
    print(n);
    print(k);
    print(row);
    print(column);
}

int main() {
    test(8, 30, 6, 4, 0.000190526);
    test(3, 2, 0, 0, 0.06250);
    test(1, 0, 0, 0, 1.00000);
    return 0;
}
