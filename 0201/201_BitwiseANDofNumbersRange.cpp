#include "../inc.h"

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {}
};

void test(int left, int right, int expect) {
    save4print(left, right);
    assert_eq_ret(expect, Solution().rangeBitwiseAnd(left, right));
}

int main() {
    test(5, 7, 4);
    test(0, 0, 0);
    test(1, 2147483647, 0);
    return 0;
}
