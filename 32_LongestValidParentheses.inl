class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> dp(s.size(), 0);
		int ret = 0;
		for (auto i = 1;i < s.size();i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					if (i >= 2)
					{
						dp[i] = dp[i - 2] + 2;
					}
					else
					{
						dp[i] = 2;
					}
				}
				else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
				{
					dp[i] = dp[i - 1] + 2;
					// add left   ()(())   the last is 4+2 not 4.
					if (i - dp[i] >= 0)
					{
						dp[i] += dp[i - dp[i]];
					}
				}
				ret = std::max(ret, dp[i]);
			}
		}
		return ret;
	}
};