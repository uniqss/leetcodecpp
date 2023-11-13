#include "../inc.h"

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256);
        int ret = 0, ssize = s.size(), l = 0;
        for (int i = 0; i < ssize; ++i) {
            char c = s[i];
            while (count[c] > 0) --count[s[l++]];
            ret = max(ret, i - l + 1);
            ++count[c];
        }
        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    Solution so;
    auto ret = so.lengthOfLongestSubstring(s);
    assert_eq_ret(expect, ret);
}

int main() {
    test("abcabcbb", 3);
    test("bbbbb", 1);
    test("pwwkew", 3);
    return 0;
}
