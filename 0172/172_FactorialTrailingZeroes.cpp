#include "../inc.h"

class Solution {
   public:
    int trailingZeroes(int n) {}
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().trailingZeroes(n));
}

int main() {
    test(30, 7);
    test(3, 0);
    test(5, 1);
    test(0, 0);
    return 0;
}
