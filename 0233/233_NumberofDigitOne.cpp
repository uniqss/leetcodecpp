#include "../inc.h"

class Solution {
   public:
    int countDigitOne(int n) {}
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().countDigitOne(n));
}

int main() {
    test(20, 12);
    test(13, 6);
    test(0, 0);
    return 0;
}