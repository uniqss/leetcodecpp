#include "../inc.h"

class Solution {
   public:
    bool isHappy(int n) {}
};

void test(int n, bool expect) {
    save4print(n);
    Solution so;
    auto ret = so.isHappy(n);
    assert_eq_ret(expect, ret);
}

int main() {
    test(1, true);
    test(19, true);
    test(2, false);
    return 0;
}
