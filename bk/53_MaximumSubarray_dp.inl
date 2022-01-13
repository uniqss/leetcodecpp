class Solution {
public:
	// using dp
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int ret = nums[0];
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		for (int i = 1;i < nums.size();i++)
		{
			dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
			ret = std::max(dp[i], ret);
		}
		return ret;
	}
};