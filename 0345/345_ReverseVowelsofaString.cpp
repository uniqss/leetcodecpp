#include "../inc.h"

class Solution {
   public:
    string reverseVowels(string s) {}
};

void test(string s, string expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().reverseVowels(s));
}

int main() {
    test("hello", "holle");
    test("leetcode", "leotcede");
    return 0;
}
