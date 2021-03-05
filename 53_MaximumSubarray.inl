class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int ret = nums[0];
		int imax = nums[0];
		for (int i = 1;i < nums.size();i++)
		{
			imax = std::max(nums[i], imax + nums[i]);
			ret = std::max(ret, imax);
		}
		return ret;
	}
};