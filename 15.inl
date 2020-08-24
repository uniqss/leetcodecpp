class Solution {
public:
    int minThree(int i, int j, int k)
    {
        if (i <= j && i <= k) return i;
        if (j <= k) return j;
        return k;
    }
	int maxThree(int i, int j, int k)
    {
        if (i >= j && i >= k) return i;
        if (j >= k) return j;
        return k;
    }
	
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        set<pair<int, int>> unique;

        unordered_map<int, int> dict;
    	for (int i = 0;i < nums.size();i++)
    	{
	        auto it = dict.find(nums[i]);
	        if (it == dict.end())
	        {
                dict[nums[i]] = 1;
	        }
            else
            {
                it->second++;
            }
    	}

    	for (int i = 0;i < nums.size();i++)
    	{
    		for (int j = i + 1;j < nums.size();j++)
    		{
                int k = 0 - nums[i] - nums[j];
                int count = 1;
                if (k == nums[i])
                {
                    ++count;
                }
                if (k == nums[j])
                {
                    ++count;
                }
                auto it = dict.find(k);
                if (it == dict.end()) continue;
    			if (it->second < count) continue;
                pair<int, int> uniqueTmp{minThree(nums[i], nums[j], k), maxThree(nums[i], nums[j], k)};
                if (unique.find(uniqueTmp) == unique.end())
                {
                    ret.push_back(vector<int>{nums[i], nums[j], k});
                    unique.insert(uniqueTmp);
                }
    		}
    	}
    	
        return ret;
    }
};