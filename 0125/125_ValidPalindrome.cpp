#include "../inc.h"

class Solution {
   public:
    bool isPalindrome(string s) {}
};

void test(string s, bool expect) {
    save4print(s);
    Solution so;
    auto ret = so.isPalindrome(s);
    assert_eq_ret(expect, ret);
}

int main() {
    test("0P", false);
    test("A man, a plan, a canal: Panama", true);
    test("race a car", false);
    test(" ", true);
    return 0;
}
