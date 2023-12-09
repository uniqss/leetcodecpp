#include "../inc.h"

class Solution {
   public:
    int numTilings(int n) {
        int64_t mod = 1e9 + 7;
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(4));
        dp[0][3] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }

        return dp[n][3];
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().numTilings(n));
}

int main() {
    test(4, 11);
    test(3, 5);
    test(1, 1);
    return 0;
}
