#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int64_t y = 0, tmp = x;
        while (tmp > 0) {
            y = y * 10 + tmp % 10;
            tmp /= 10;
        }
        return y == x;
    }
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
