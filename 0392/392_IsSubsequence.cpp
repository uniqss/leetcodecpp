#include "../inc.h"

class Solution {
   public:
    bool isSubsequence(string s, string t) {}
};

void test(string s, string t, bool expect) {
    save4print(s, t);
    assert_eq_ret(expect, Solution().isSubsequence(s, t));
}

int main() {
    test("", "ahbgdc", true);
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    return 0;
}
