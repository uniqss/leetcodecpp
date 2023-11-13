#include "../inc.h"

class Solution {
   public:
    int numTilings(int n) {
    }
};

void test(int n, int expect) {
    Solution so;
    auto ret = so.numTilings(n);
    assert_eq_ret(expect, ret);
    print(n);
}

int main() {
    test(4, 11);
    test(3, 5);
    test(1, 1);
    return 0;
}
