#include "../inc.h"

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {}
};

void test(string text1, string text2, int expect) {
    Solution so;
    auto ret = so.longestCommonSubsequence(text1, text2);
    assert_eq_ret(expect, ret);
    print(text1);
    print(text2);
}

int main() {
    test("bsb", "b", 1);
    test("bsbininm", "jmjkbkjkv", 1);
    test("abcde", "ace", 3);
    test("abc", "abc", 3);
    test("abc", "def", 0);
    return 0;
}
