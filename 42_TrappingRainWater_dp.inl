/*
把整个堆当作一个模型往右推，留下阴影left_max
把整个堆当作一个模型往左推，留下阴影right_max
循环取积 min(left_max[i], right_max[i]) - height[i]
*/
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2)
		{
			return 0;
		}

		int ret = 0;
		int size = height.size();
		vector<int> left_max(size);
		vector<int> right_max(size);
		left_max[0] = height[0];
		for (int i = 1;i < size;i++)
		{
			left_max[i] = std::max(left_max[i - 1], height[i]);
		}

		right_max[size - 1] = height[size - 1];
		for (int i = size - 2;i >= 0;i--)
		{
			right_max[i] = std::max(right_max[i + 1], height[i]);
		}

		for (int i = 0;i < size - 1;i++)
		{
			ret += std::min(left_max[i], right_max[i]) - height[i];
		}

		return ret;
	}
};
