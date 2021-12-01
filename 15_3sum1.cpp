#include "stl.h"

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_set<int> setMaxNum;
        int i = 0;
        int j = 0;
        int k = 0;
        for (; i < nums.size() - 2; ++i) {
            for (j = i + 1; j < nums.size() - 1; ++j) {
                for (k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        int max = std::max(std::max(nums[i], nums[j]), nums[k]);
                        if (setMaxNum.find(max) != setMaxNum.end()) continue;
                        setMaxNum.insert(max);

                        ret.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return ret;
    }
};

int main() {
    vector<int> vi = {-1, 0, 1, 2, -1, -4};
    Solution s;
    auto ret = s.threeSum(vi);
    pvvi(ret);
    return 0;
}
