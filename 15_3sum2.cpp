#include "stl.h"

/*
需要注意的点：
    要先排序，双指针在这种问题中必须先排序。这里利用的就是这种有序的规则。very tricky
    防重的静态前判定：静态变量使用前先判定一下是不是和上一个一样，一样则跳
    防重的动态后判定：动态左右变量加入结果后，移动左右前，要进行一次当前值的判定，左重则右移左变量，右重则左移右变量。
    别忘了相等时左右变量的移动
*/
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = 0;
        int numsi = 0;
        int sum = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = nums.size() - 1;
            numsi = nums[i];
            while (l < r) {
                sum = nums[l] + nums[r] + numsi;
                if (sum < 0)
                    ++l;
                else if (sum > 0)
                    --r;
                else {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l + 1] == nums[l]) ++l;
                    while (l < r && nums[r - 1] == nums[r]) --r;
                    ++l;
                    --r;
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