#include "../inc.h"

/*
这里的难点就在于dp的状态转移方程
dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
dp[i][j]的意义是以 (i, j) 为右下角的点的最大方块的边长
*/
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxside = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxside = max(maxside, dp[i][j]);
                }
            }
        }
        return maxside * maxside;
    }
};

void test(vector<vector<string>>&& matrix, int expect) {
    save4print(matrix);
    auto m = vvs2vvc(matrix);
    assert_eq_ret(expect, Solution().maximalSquare(m));
}

int main() {
    test({{"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}},
         4);
    test({{"0", "1"}, {"1", "0"}}, 1);
    test({{"0"}}, 0);
    return 0;
}
