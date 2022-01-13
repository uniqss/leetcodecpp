class Solution {
public:
	bool isMatch(string s, string p) {
		int sLen = s.size();
		auto pLen = p.size();

		vector<vector<bool>> f(sLen + 1, vector<bool>(pLen + 1, false));

		f[0][0] = true;
		
		for (int j = 2; j <= pLen; j++)
			f[0][j] = p[j - 1] == '*' && f[0][j - 2];

		for (int i = 1;i <=sLen;i++)
			for (int j = 1;j <= pLen;j++)
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

		return f[sLen][pLen];
	}
};