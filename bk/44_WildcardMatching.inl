class Solution {
public:
	bool isMatch(string s, string p) {
		int slen = s.size();
		int plen = p.size();

		vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
		dp[0][0] = true;
		for (int j = 1;j <= plen;j++)
		{
			for (int i = 0;i <= slen;i++)
			{
				if (p[j - 1] == '*')
				{
					if (dp[i][j - 1]) dp[i][j] = true;
					if (i > 0 && dp[i - 1][j]) dp[i][j] = true;
				}
				else if (p[j - 1] == '?')
				{
					if (i > 0 && dp[i - 1][j - 1]) dp[i][j] = true;
				}
				else
				{
					if (i > 0 && dp[i - 1][j - 1] && p[j - 1] == s[i - 1]) dp[i][j] = true;
				}
			}
		}
		return dp[slen][plen];
	}
};