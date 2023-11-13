#include "../inc.h"

class Solution {
   public:
    int numSquares(int n) {}
};

void test(int n, int expect) {
    Solution so;
    auto ret = so.numSquares(n);
    assert_eq_ret(expect, ret);
    print(n);
}

int main() {
    test(12, 3);
    test(13, 2);
    test(1, 1);
    test(2, 2);
    test(3, 3);
    test(4, 1);
    return 0;
}