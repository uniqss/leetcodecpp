#include "../inc.h"

class Solution {
   public:
    string reverseWords(string s) {}
};

void test(string&& s, string expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().reverseWords(s));
}

int main() {
    test("a", "a");
    test("the sky is blue", "blue is sky the");
    test("  hello world  ", "world hello");
    test("a good   example", "example good a");
    test("example good a", "a good example");
    return 0;
}
