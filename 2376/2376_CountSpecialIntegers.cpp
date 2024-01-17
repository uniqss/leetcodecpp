#include "../inc.h"

class Solution {
   public:
    int countSpecialNumbers(int n) {}
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().countSpecialNumbers(n));
}

int main() {
    test(585362300, 4104810);
    test(20, 19);
    test(5, 5);
    test(135, 110);
    return 0;
}
