class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(grid);
		for (int i = 1;i < m;i++)
		{
			dp[i][0] += dp[i - 1][0];
		}
		for (int j = 1;j < n;j++)
		{
			dp[0][j] += dp[0][j - 1];
		}
		for (int i = 1;i < m;i++)
		{
			for (int j = 1;j < n;j++)
			{
				if (dp[i-1][j] <= dp[i][j - 1])
				{
					dp[i][j] += dp[i - 1][j];
				}
				else {
					dp[i][j] += dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};