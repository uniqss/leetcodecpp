class Solution {
public:
	bool isMatch(string s, string p) {
		/*
		 * f[i][j] 的意义：  s[0 ... i - 1] 与 p[0 ... j - 1]是否匹配，注意下标要 - 1
		 *
		 * 
		 */
		int m = s.size(); int n = p.size();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

		f[0][0] = true;

		// aaaaabbb   c*aaaaabbb这种 首位c*直接过滤的情况，要把f[0][j]设置一下
		for (int j = 1; j <= n; j++)
			f[0][j] = j > 1 && p[j - 1] == '*' && f[0][j - 2];

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (p[j - 1] != '*')
				{
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
				else
				{
					f[i][j] = f[i][j - 2] || (f[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
				}
			}
		}
		return f[m][n];
	}
};