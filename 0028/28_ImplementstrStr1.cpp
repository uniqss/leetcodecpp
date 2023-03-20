#include "../inc.h"

// 中文官方
class Solution {
   public:
    int strStr(string haystack, string needle) {
        int ret = 0;
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        if (m > n) return -1;

        vector<int> next(m);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                ++j;
            }
            next[i] = j;
        }
        print(next);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == m) {
                return i - m + 1;
            }
        }

        return -1;
    }
};

void test(string&& haystack, string&& needle, int expect) {
    Solution so;
    auto ret = so.strStr(haystack, needle);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(haystack);
        print(needle);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test("hello", "ll", 2);
    test("aaaaa", "bba", -1);
    test("aabaabaaf", "aabaaf", 3);
    test("aafaabaabaabaaf", "aabaabaab", 3);
    return 0;
}