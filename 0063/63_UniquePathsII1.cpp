#include "../inc.h"

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] != 1) dp[i][0] = dp[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] != 1) dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] != 1) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

void test(vector<vector<int>>&& obstacleGrid, int expect) {
    save4print(obstacleGrid);
    assert_eq_ret(expect, Solution().uniquePathsWithObstacles(obstacleGrid));
}

int main() {
    test({{1}}, 0);
    test({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2);
    test({{0, 1}, {0, 0}}, 1);
    return 0;
}
