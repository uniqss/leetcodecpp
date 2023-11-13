#include "../inc.h"

class Solution {
   public:
    int calculate(string s) {}
};

void test(string s, int expect) {
    save4print(s);
    Solution so;
    auto ret = so.calculate(s);
    assert_eq_ret(expect, ret);
}
int main() {
    test("2147483647", 2147483647);
    test("1-(     -2)", 3);
    test("1+1", 2);
    test(" 2-1 + 2 ", 3);
    test("(1+(4+5+2)-3)+(6+8)", 23);
    return 0;
}