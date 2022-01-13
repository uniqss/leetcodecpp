class Solution {
public:
	bool isMatch(string s, string p) {
		/*
		 * f[i][j] �����壺  s[0 ... i - 1] �� p[0 ... j - 1]�Ƿ�ƥ�䣬ע���±�Ҫ - 1
		 *
		 * 
		 */
		int m = s.size(); int n = p.size();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

		f[0][0] = true;

		// aaaaabbb   c*aaaaabbb���� ��λc*ֱ�ӹ��˵������Ҫ��f[0][j]����һ��
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