#include "../inc.h"

class Solution {
   public:
    bool isValid(string s) {}
};

void test(const string& s, bool expected) {
    Solution so;
    bool ret = so.isValid(s);
    if (expected != ret) {
        praw("!!!!!!! not ok");
        praw(s);
        praw(expected);
        praw(ret);
        pnewline();
    } else {
        praw("ok");
    }
}

int main() {
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    return 0;
}
