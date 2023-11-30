#include "../inc.h"

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 2, vector<int>(n + 1, m + n));
        dp[1][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i > 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 2][j] + 1);
                }
                if (j > 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 2] + 1);
                }
                if (i > 1 && j > 0) {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = min(dp[i][j], dp[i - 2][j - 1]);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + 1);
                    }
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