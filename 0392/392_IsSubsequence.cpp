#include "../inc.h"

class Solution {
   public:
    bool isSubsequence(string s, string t) {}
};

void test(string s, string t, bool expect) {
    Solution so;
    auto ret = so.isSubsequence(s, t);
    assert_eq_ret(expect, ret);
    print(s);
    print(t);
}

int main() {
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    return 0;
}
