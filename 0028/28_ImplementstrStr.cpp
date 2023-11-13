#include "../inc.h"

class Solution {
   public:
    int strStr(string haystack, string needle) {
        // todo@uniqs 至少三天后，确定忘记了官方kmp算法以后，重新学习整理kmp算法，这里代码先删了
    }
};

void test(string&& haystack, string&& needle, int expect) {
    save4print(haystack, needle);
    assert_eq_ret(expect, Solution().strStr(haystack, needle));
}

int main() {
    test("sadbutsad", "sad", 0);
    test("hello", "ll", 2);
    test("aaaaa", "bba", -1);
    test("aabaabaaf", "aabaaf", 3);
    return 0;
}