#include "../inc.h"

class Solution {
   public:
    bool isIsomorphic(string s, string t) {}
};

void test(string s, string t, bool expect) {
    save4print(s, t);
    assert_eq_ret(expect, Solution().isIsomorphic(s, t));
}

int main() {
    test("badc", "baba", false);
    test("egg", "add", true);
    test("foo", "bar", false);
    test("paper", "title", true);
    return 0;
}
