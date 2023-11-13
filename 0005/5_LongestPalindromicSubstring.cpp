#include "../inc.h"

class Solution {
   public:
    string longestPalindrome(string s) {}
};

void test(string s, string expect) {
    save4print(s);
    auto ret = Solution().longestPalindrome(s);
    bool isPalinDrome = isStrPalindrome(ret);
    assert_retnone(ret.size() == expect.size() && isPalinDrome);
}

int main() {
    test("aaaa", "aaaa");
    test("babad", "bab");
    test("cbbd", "bb");
    return 0;
}
