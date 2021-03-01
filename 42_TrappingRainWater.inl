class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2)
		{
			return 0;
		}

		// 问题三分，增长段、平滑段、减少段
		int maxIdxL = 0;
		int maxIdxR = 0;
		int max = 0;
		for (int i = 0;i < height.size();i++)
		{
			max = std::max(max, height[i]);
		}
		bool first = true;
		for (int i = 0; i < height.size(); i++)
		{
			if (height[i] >= max)
			{
				if (first)
				{
					first = false;
					maxIdxL = i;
				}
				maxIdxR = i;
			}
		}
		int ret = 0;
		// 增区间
		int currMax = 0;
		for (int i = 0; i < maxIdxL; i++)
		{
			if (height[i] < currMax)
			{
				ret += currMax - height[i];
			}
			if (height[i] > currMax)
			{
				currMax = height[i];
			}
		}
		// 平区间
		for (int i = maxIdxL + 1; i < maxIdxR; i++)
		{
			if (height[i] < max)
			{
				ret += max - height[i];
			}
		}
		// 减区间
		currMax = 0;
		for (int i = height.size() - 1; i > maxIdxR; i--)
		{
			if (height[i] < currMax)
			{
				ret += currMax - height[i];
			}
			if (height[i] > currMax)
			{
				currMax = height[i];
			}
		}
		return ret;
	}
};