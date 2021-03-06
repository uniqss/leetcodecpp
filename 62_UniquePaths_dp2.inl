class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m > n) { int tmp = m; m = n; n = tmp; }
		vector<int> dp(m, 1);
		int left = 0;
		for (int j = 1;j < n;j++)
		{
			left = 0;
			for (int i = 0;i < m;i++)
			{
				dp[i] += left;
				left = dp[i];
			}
		}
		return dp[m - 1];
	}
};