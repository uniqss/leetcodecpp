#include "../inc.h"

class Solution {
   public:
    int minFlips(int a, int b, int c) {}
};

void test(int a, int b, int c, int expect) {
    Solution so;
    auto ret = so.minFlips(a, b, c);
    assert_eq_ret(expect, ret);
    print(a);
    print(b);
    print(c);
}

int main() {
    test(2, 6, 5, 3);
    test(4, 2, 7, 1);
    test(1, 2, 3, 0);
    return 0;
}