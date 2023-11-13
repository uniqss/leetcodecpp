#include "../inc.h"

class Solution {
   public:
    int tribonacci(int n) {}
};

void test(int n, int expect) {
    Solution so;
    auto ret = so.tribonacci(n);
    assert_eq_ret(expect, ret);
    print(n);
}

int main() {
    test(4, 4);
    test(25, 1389537);
    return 0;
}
