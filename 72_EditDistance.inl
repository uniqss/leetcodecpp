class Solution {
public:
	int minDistance(const string& word1, const string& word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		if (len1 == 0) return len2;
		if (len2 == 0) return len1;
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1;i <= len1;i++)
		{
			dp[i][0] = i;
		}
		for (int j = 1;j <= len2;j++)
		{
			dp[0][j] = j;
		}
		for (int i = 1;i <= len1;i++)
		{
			for (int j = 1;j <= len2;j++)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					int disReplace = dp[i - 1][j - 1]; // 把word1[i - 1]替换成word2[j - 1]
					int disInsert = dp[i][j - 1]; // 插入word2[j - 1]
					int disDelete = dp[i - 1][j]; // 把word1[i - 1]干掉
					dp[i][j] = std::min(disReplace, std::min(disInsert, disDelete)) + 1;
				}
			}
		}
		return dp[len1][len2];
	}
};