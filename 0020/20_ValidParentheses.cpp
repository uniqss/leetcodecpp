#include "../inc.h"

class Solution {
   public:
    bool isValid(string s) {}
};

void test(const string& s, bool expected) {
    save4print(s);
    Solution so;
    bool ret = so.isValid(s);
    assert_eq_ret(expected, ret);
}

int main() {
    test("]", false);
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    return 0;
}
