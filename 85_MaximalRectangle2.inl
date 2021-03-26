class Solution {
public:
	int maximalRectangle(const vector<vector<char>>& matrix) {
		if (matrix.empty())
		{
			return 0;
		}
		int col = matrix.size();
		int row = matrix[0].size();
		vector<vector<int>> maxcol(col + 1, vector<int>(row + 1, 0));
		vector<vector<vector<int>>> dp(col + 1, vector<int>(row + 1, vector<int>(col + 1, 0)));
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (matrix[i - 1][j - 1] == '1')
				{
					maxcol[i][j] = maxcol[i][j - 1] + 1;
					for (int k = 1;j <= )
					{
					}
					int valTopDown = 0;
					int top = dp[i][j - 1];
					int toprow = maxrow[i][j - 1];
					int leftrow = maxrow[i - 1][j];
					if (toprow <= leftrow + 1)
					{
						valTopDown = dp[i][j - 1] + toprow;

					}
				}
			}
		}
	}
};
