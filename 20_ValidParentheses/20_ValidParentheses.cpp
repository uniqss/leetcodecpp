#include "../stl.h"

class Solution {
   public:
    bool isValid(string s) {
    }
};

void test(const string& s, bool expected) {
    Solution so;
    praw(s);
    bool ret = so.isValid(s);
    if (expected != ret) {
        praw("!!!!!!! not ok");
    } else {
        praw("ok");
    }
    pnewline();
}

int main() {
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    return 0;
}
