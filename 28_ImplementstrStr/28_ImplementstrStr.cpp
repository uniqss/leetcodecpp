#include "../inc.h"

class Solution {
   public:
    int strStr(string haystack, string needle) {}
};

void test(string&& haystack, string&& needle, int expect) {
    Solution so;
    auto ret = so.strStr(haystack, needle);
    if (ret == expect) {
        praw("ok.");
    } else {
        praw("not ok.");
        praw(haystack);
        praw(needle);
        praw(expect);
        praw(ret);
        pnewline();
    }
}

int main() {
    test("hello", "ll", 2);
    test("aaaaa", "bba", -1);
    test("aabaabaaf", "aabaaf", 3);
    return 0;
}