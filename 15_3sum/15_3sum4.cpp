#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int imax = nums.size() - 2;
        int sum = 0;
        for (size_t i = 0; i <= imax; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                }
                if (sum >= 0) {
                    --r;
                    while (r > l && nums[r] == nums[r + 1]) --r;
                }
                if (sum <= 0) {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
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
        praw("ok.");
    } else {
        praw("not ok.");
        pvraw(nums);
        pvvraw(expect);
        pvvraw(ret);
    }
}

int main() {
    test({-2, 0, 0, 2, 2}, {{-2, 0, 2}});
    test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    test({}, {});
    test({0}, {});
    test({3, 0, -2, -1, 1, 2}, {{3, -1, -2}, {2, -2, 0}, {1, -1, 0}});

    return 0;
}
