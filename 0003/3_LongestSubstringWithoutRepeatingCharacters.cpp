#include "../inc.h"

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {}
};

void test(string s, int expect) {
    save4print(s);
    Solution so;
    auto ret = so.lengthOfLongestSubstring(s);
    assert_eq_ret(expect, ret);
}

int main() {
    test("abcabcbb", 3);
    test("bbbbb", 1);
    test("pwwkew", 3);
    return 0;
}
