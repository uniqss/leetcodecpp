#include "../inc.h"

class Solution {
   public:
    string reverseVowels(string s) {}
};

void test(string s, string expect) {
    Solution so;
    auto ret = so.reverseVowels(s);
    assert_eq_ret(expect, ret);
    print(s);
}

int main() {
    test("hello", "holle");
    test("leetcode", "leotcede");
    return 0;
}
