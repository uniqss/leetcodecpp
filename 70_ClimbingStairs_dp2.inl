class Solution {
public:
	int climbStairs(int n) {
		int dpi1 = 1;
		int dpi2 = 1;
		int result = 1;
		for (int i = 2;i <= n;i++)
		{
			result = dpi1 + dpi2;
			dpi2 = dpi1;
			dpi1 = result;
		}
		return result;
	}
};