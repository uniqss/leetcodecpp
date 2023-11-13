#include "../inc.h"

class Solution {
   public:
    int minDistance(string word1, string word2) {
        /*
        s = word1, t = word2;
        m = word1.size(), n = word2.size();
        dp[i][j]
        s[i - 1] == t[j - 1]
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1])
        s[i - 1] != t[j - 1]
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
        */
        auto &s = word1, &t = word2;
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

void test(string word1, string word2, int expect) {
    save4print(word1, word2);
    assert_eq_ret(expect, Solution().minDistance(word1, word2));
}

int main() {
    test("plasma", "altruism", 6);
    test("horse", "ros", 3);
    test("intention", "execution", 5);
    return 0;
}