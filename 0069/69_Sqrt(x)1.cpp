#include "../inc.h"

class Solution {
   public:
    int mySqrt(int x) {}
};

void test(int x, int expect) {
    save4print(x);
    assert_eq_ret(expect, Solution().mySqrt(x));
}

int main() {
    test(1, 1);
    test(2, 1);
    test(3, 1);
    test(4, 2);
    test(5, 2);
    test(8, 2);
    test(9, 3);
    test(2147395599, 46339);
    return 0;
}
