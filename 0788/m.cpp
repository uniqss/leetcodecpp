#include "../inc.h"

class Solution {
   public:
    int rotatedDigits(int n) {}
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().rotatedDigits(n));
}

int main() {
    test(10, 4);
    test(1, 0);
    test(2, 1);
    return 0;
}