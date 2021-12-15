#include "../stl.h"

class Solution {
   public:
    bool isValid(string s) {
    }
};

void test(const string& s, bool expected) {
    Solution so;
    ps(s);
    bool ret = so.isValid(s);
    if (expected != ret) {
        ps("!!!!!!! not ok");
    } else {
        ps("ok");
    }
    pnewline();
}

int main() {
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    return 0;
}
