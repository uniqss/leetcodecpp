#include "../inc.h"

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        int maxlen = 1, pos = 0, currlen;
        auto dpijpositive = [&dp](int i, int j) {
            if (i > j) return true;
            return dp[i][j] > 0;
        };
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (dpijpositive(i + 1, j - 1) && s[i] == s[j]) {
                    currlen = j - i + 1;
                    if (currlen > maxlen) {
                        maxlen = currlen;
                        pos = i;
                    }
                    dp[i][j] = currlen;
                }
            }
        }

        return s.substr(pos, maxlen);
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
