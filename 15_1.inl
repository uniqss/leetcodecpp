class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        unordered_map<int, int> dict;
    	
        int left = 0; int right = nums.size() - 1;
        int mid = (left + right) / 2;
        int sumleftright = 0;
        while (left < right)
        {
            sumleftright = nums[left] + nums[right];

        }
    	
        return ret;
    }
};