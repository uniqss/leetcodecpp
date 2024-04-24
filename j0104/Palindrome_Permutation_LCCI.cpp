#include "../inc.h"

class Solution {
   public:
    bool canPermutePalindrome(string s) {}
};

void test(std::string&& s, bool expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().canPermutePalindrome(s));
}

int main() {
    test("code", false);
    test("aab", true);
    test("tactcoa", true);
    return 0;
}
