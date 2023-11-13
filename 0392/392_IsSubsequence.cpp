#include "../inc.h"

class Solution {
   public:
    bool isSubsequence(string s, string t) {}
};

void test(string s, string t, bool expect) {
    save4print(s);
    save4print(t);
    Solution so;
    auto ret = so.isSubsequence(s, t);
    assert_eq_ret(expect, ret);
}

int main() {
    test("", "ahbgdc", true);
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    return 0;
}
