#include "../inc.h"

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if (m + n != t) return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i > 0) dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                if (j > 0) dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
};

void test(string s1, string s2, string s3, bool expect) {
    save4print(s1, s2, s3);
    assert_eq_ret(expect, Solution().isInterleave(s1, s2, s3));
}

int main() {
    test("aabcc", "dbbca", "aadbbcbcac", true);
    test("aabcc", "dbbca", "aadbbbaccc", false);
    test("", "", "", true);
    return 0;
}
