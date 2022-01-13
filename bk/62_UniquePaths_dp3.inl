class Solution {
public:
	int uniquePaths(int m, int n) {
		/*
		* . . . . .
		* o . . . .
		* o o . . .
		* o o o . .
		*/
		if (m < n) { int tmp = m; m = n; n = tmp; }
		vector<vector<int>> dp(m, vector<int>(n, 1));
		int top, left;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j <= i && j < n; j++)
			{
				top = i >= (j - 1) ? dp[i][j - 1] : dp[j - 1][i];
				left = (i - 1) >= j ? dp[i - 1][j] : dp[j][i - 1];
				dp[i][j] = top + left;
			}
		}
		return dp[m - 1][n - 1];
	}
};