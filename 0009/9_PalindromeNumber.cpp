#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(int x) {}
};

void test(int x, bool expect) {
    save4print(x);
    assert_eq_ret(expect, Solution().isPalindrome(x));
}

int main() {
    test(1234567899, false);
    test(121, true);
    test(-121, false);
    test(10, false);
    return 0;
}
