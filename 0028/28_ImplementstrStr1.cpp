#include "../inc.h"

// 中文官方
class Solution {
   public:
    int strStr(string str, string pattern) {
        int ret = 0;
        int n = str.size(), m = pattern.size();
        if (m == 0) return 0;
        if (m > n) return -1;

        vector<int> next(m);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
            if (pattern[i] == pattern[j]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && str[i] != pattern[j]) j = next[j - 1];
            if (str[i] == pattern[j]) ++j;
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
    test("hello", "ll", 2);
    test("aaaaa", "bba", -1);
    test("aabaabaaf", "aabaaf", 3);
    test("aafaabaabaabaaf", "aabaabaab", 3);
    return 0;
}