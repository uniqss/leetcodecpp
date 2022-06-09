#include "../inc.h"

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        int next[m];
        genNext(next, needle);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if (haystack[i] == needle[j]) ++j;
            if (j == m) return i - m + 1;
        }
        return -1;
    }
    void genNext(int* next, const string& s) {
        next[0] = 0;
        for (int i = 1, j = 0; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) j = next[j - 1];
            if (s[i] == s[j]) ++j;
            next[i] = j;
        }
    }
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