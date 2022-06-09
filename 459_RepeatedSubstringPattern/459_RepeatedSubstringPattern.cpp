#include "../inc.h"

class Solution {
   public:
    bool repeatedSubstringPattern(string s) {}
};

void test(string&& s, bool expect) {
    Solution so;
    auto ret = so.repeatedSubstringPattern(s);
    if (ret == expect) {
        praw("ok");
    } else {
        praw("not ok");
        praw(s);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test("abac", false);
    test("abab", true);
    test("abcabcabcabc", true);
    return 0;
}
