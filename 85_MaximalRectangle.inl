/*
思路整理：
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
以左上角为起点(x1,y1)，以右下角为终点(x2,y2)，形成dp
dp[(x1,y1)][(x2,y2)] =
	Matrix(x2, y2) &&
	dp[(x1, y1)][(x2, y2-1)] &&
	dp[(x1, y2)][(x2-1, y2)]
因为 0 <= x, y <= 200，所以优化一下用x*256+y作为它的坐标
可以直接左移x<<8+y
*/
class Solution {
public:
	int maximalRectangle(const vector<vector<char>>& matrix) {
		int ret = 0;
		if (matrix.empty())
		{
			return 0;
		}
		int col = matrix.size();
		int row = matrix[0].size();
		if (row == 0 && col == 0)
		{
			return 0;
		}

		auto pairHash = [](pair<pair<uint8_t, uint8_t>, pair<uint8_t, uint8_t>> p)
		{return 
			(((uint32_t)p.first.first) << 24) ||
			(((uint32_t)p.first.second) << 16)||
			(((uint32_t)p.second.first) << 8) ||
			(((uint32_t)p.first.second))
			; };
		unordered_map < pair<pair<uint8_t, uint8_t>, pair<uint8_t, uint8_t>>, int, decltype(pairHash)> dp(65536, pairHash);
		for (uint8_t x1 = 0; x1 < row; x1++)
		{
			for (uint8_t y1 = 0; y1 < col; y1++)
			{
				auto from = make_pair(x1, y1);
				if (matrix[y1][x1] == '0')
				{
					continue;
				}
				for (uint8_t x2 = x1; x2 < row; x2++)
				{
					for (uint8_t y2 = y1; y2 < col; y2++)
					{
						auto to = make_pair(x2, y2);
						if (matrix[y2][x2] == '0')
						{
							continue;
						}
						else
						{
							// 四种情况，同位、同行、同列、不同行不同列

							if (y2 == y1 && x2 == x1)// 同位
							{
								dp[make_pair(from, to)] = 1;
								ret = std::max(dp[make_pair(from, to)], ret);
							}
							else if (y2 == y1)// 同行
							{
								auto it = dp.find(make_pair(from, make_pair(x2 - 1, y2)));
								if (it != dp.end())
								{
									dp[make_pair(from, to)] = it->second + 1;
									ret = std::max(dp[make_pair(from, to)], ret);
								}
							}
							else if (x2 == x1)// 同列
							{
								auto it = dp.find(make_pair(from, make_pair(x2, y2 - 1)));
								if (it != dp.end())
								{
									dp[make_pair(from, to)] = it->second + 1;
									ret = std::max(dp[make_pair(from, to)], ret);
								}
							}
							else// 不同行不同列
							{
								auto itTop = dp.find(make_pair(from, make_pair(x2, y2 - 1)));
								if (itTop != dp.end())
								{
									auto itLeft = dp.find(make_pair(make_pair(x1, y1), make_pair(x2 - 1, y2)));
									if (itLeft != dp.end())
									{
										dp[make_pair(from, to)] = itTop->second + (x2 - x1 + 1);
										ret = std::max(dp[make_pair(from, to)], ret);
									}
								}
							}
						}
					}
				}
			}
		}
		return ret;
	}
};
