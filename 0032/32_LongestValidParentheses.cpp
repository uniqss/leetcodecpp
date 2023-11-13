#include "../inc.h"

class Solution {
   public:
    int longestValidParentheses(string s) {}
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().longestValidParentheses(s));
}

int main() {
    test("((()))())", 8);
    test("()(())", 6);
    test("()", 2);
    test("(()", 2);
    test(")()())", 4);
    test("", 0);
    return 0;
}
