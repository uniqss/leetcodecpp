class Solution {
public:
	int calcVolumn(int left, int right, const vector<int>& height) { return (right - left) * min(height[left], height[right]); }
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int volumn = calcVolumn(left, right, height);
		int temp = 0;
		while (true)
		{
			if (height[left] < height[right])
			{
				temp = left + 1;
				while (temp < right && height[temp] < height[left])
				{
					++temp;
				}
				if (temp >= right)
				{
					break;
				}
				int tempVolumn = calcVolumn(temp, right, height);
				if (tempVolumn > volumn)
				{
					volumn = tempVolumn;
				}
				left = temp;
			}
			else
			{
				temp = right - 1;
				while (temp > left && height[temp] < height[right])
				{
					--temp;
				}
				if (temp <= left)
				{
					break;
				}
				int tempVolumn = calcVolumn(left, temp, height);
				if (tempVolumn > volumn)
				{
					volumn = tempVolumn;
				}
				right = temp;
			}
		}
		return volumn;
	}
};