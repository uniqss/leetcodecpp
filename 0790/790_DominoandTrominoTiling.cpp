#include "../inc.h"

class Solution {
   public:
    int numTilings(int n) {}
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().numTilings(n));
}

int main() {
    test(1, 1);
    test(2, 2);
    test(3, 5);
    test(4, 11);
    return 0;
}
