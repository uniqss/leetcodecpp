#include "../inc.h"

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        if (m > n) return -1;
        vector<int> next(m);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) j = next[j - 1];
            if (needle[i] == needle[j]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if (haystack[i] == needle[j]) ++j;
            if (j == m) return i - m + 1;
        }
        return -1;
    }
};

void test(string&& haystack, string&& needle, int expect) {
    save4print(haystack, needle);
    assert_eq_ret(expect, Solution().strStr(haystack, needle));
}

int main() {
    test("", "a", -1);
    test("a", "", 0);
    test("", "", 0);
    test("aabaaabaaac", "aabaaac", 4);
    test("sadbutsad", "sad", 0);
    test("ltcode", "lto", -1);
    test("leetcode", "leeto", -1);
    test("hello", "ll", 2);
    test("aaaaa", "bba", -1);
    test("aabaabaaf", "aabaaf", 3);
    return 0;
}