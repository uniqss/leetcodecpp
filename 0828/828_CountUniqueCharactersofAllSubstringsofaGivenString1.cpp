#include "../inc.h"

// 暴力解，对的，但是会超时
class Solution {
   public:
    int uniqueLetterString(string s) {
        int ret = 0, n = s.size();
        for (int l = 1; l <= n; ++l) {
            vector<int> curr(26);
            for (int i = 0; i < l - 1; ++i) ++curr[s[i] - 'A'];
            for (int i = l - 1; i < n; ++i) {
                ++curr[s[i] - 'A'];
                if (i > l - 1) --curr[s[i - l] - 'A'];
                int value = 0;
                for (int j = 0; j < 26; ++j) {
                    if (curr[j] == 1) ++value;
                }
                ret += value;
            }
        }
        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().uniqueLetterString(s));
}

int main() {
    test("ABC", 10);
    test("ABA", 8);
    test("LEETCODE", 92);
    return 0;
}
