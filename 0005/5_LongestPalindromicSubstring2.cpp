#include "../inc.h"

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size(), maxlen = 1, maxstart = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l <= n - len; ++l) {
                int r = l + len - 1;
                if (len == 1) {
                    dp[l][r] = 1;
                } else if (len == 2) {
                    dp[l][r] = s[l] == s[r] ? 2 : 0;
                } else {
                    dp[l][r] = s[l] == s[r] && dp[l + 1][r - 1] > 0 ? dp[l + 1][r - 1] + 2 : 0;
                }
                if (dp[l][r] > maxlen) {
                    maxlen = dp[l][r];
                    maxstart = l;
                }
            }
        }
        return s.substr(maxstart, maxlen);
    }
};

void test(string s, string expect) {
    save4print(s, expect);
    auto ret = Solution().longestPalindrome(s);
    bool isPalinDrome = isStrPalindrome(ret);
    save4print(ret, isPalinDrome);
    assert_retnone(ret.size() == expect.size() && isPalinDrome);
}

int main() {
    test("aacabdkacaa", "aca");
    test("aaaa", "aaaa");
    test("babad", "bab");
    test("cbbd", "bb");
    return 0;
}
