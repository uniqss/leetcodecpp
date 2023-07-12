#include "../inc.h"

/*
很久以后回刷的回忆总结
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int nsize = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nsize; ++i) {
            // 第一个数一定是唯一的，不存在有两个解，第一个数是不唯一的
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nsize - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum > 0) {
                    // -2 0 0 2 2  这种，先把r回拨到最后一个与当前相同的位置
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    // 再把r再往左移一下。
                    // 与上一行合并，达到效果：找到下一个与当前r值不相同的第1个r，从最右的2，找到最右的0
                    --r;
                } else if (sum < 0) {
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    ++l;
                } else {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    ++l;
                }
            }
        }
        return ret;
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.threeSum(nums);
    std::for_each(ret.begin(), ret.end(), [](vector<int>& vi) { std::sort(vi.begin(), vi.end()); });
    std::sort(ret.begin(), ret.end());
    std::for_each(expect.begin(), expect.end(), [](vector<int>& vi) { std::sort(vi.begin(), vi.end()); });
    std::sort(expect.begin(), expect.end());
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums);
        print(expect);
        print(ret);
    }
}

int main() {
    test({-4, 0, 2, 2, 3}, {{-4, 2, 2}});
    test({-2, 0, 0, 2, 2}, {{-2, 0, 2}});
    test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    test({}, {});
    test({0}, {});
    test({3, 0, -2, -1, 1, 2}, {{3, -1, -2}, {2, -2, 0}, {1, -1, 0}});

    return 0;
}
