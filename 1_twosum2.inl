#include "stl.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapExist;
        for (int i = 0;i < nums.size();++i) {
            auto it = mapExist.find(target - nums[i]);
            if (it != mapExist.end()) {
                return {i, it->second};
            } else {
                mapExist[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};