class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0) return 0;
		stack<int> stackIdx;
		heights.push_back(0);
		int maxArea = 0;
		for (int i = 0;i < heights.size();i++)
		{
			while (!stackIdx.empty() && heights[i] < heights[stackIdx.top()])
			{
				int idx = stackIdx.top();
				stackIdx.pop();
				int width = i;
				if (!stackIdx.empty())
				{
					width = i - stackIdx.top() - 1;
				}
				int height = heights[idx];
				int area = width * height;
				maxArea = std::max(area, maxArea);
			}
			stackIdx.push(i);
		}

		return maxArea;
	}
};