#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        ret.emplace_back(nums);

        size_t nsize = nums.size();
        while (true) {
            int pos = -1;
            for (size_t i = nsize - 1; i > 0; --i) {
                if (nums[i] > nums[i - 1]) {
                    pos = i - 1;
                    break;
                }
            }
            if (pos == -1) break;
            int right_pos = -1;
            int right_val = INT_MAX;
            for (size_t i = nsize - 1; i > pos; --i) {
                if (nums[i] > nums[pos] && nums[i] < right_val) {
                    right_val = nums[i];
                    right_pos = i;
                }
            }
            swap(nums[pos], nums[right_pos]);
            if (pos < nsize - 2) sort(nums.begin() + pos + 1, nums.end());
            ret.emplace_back(nums);
        }

        return ret;
    }
};

void test(vector<int>&& nums, vector<vector<int>>&& expect) {
    save4print(nums);
    auto ret = Solution().permuteUnique(nums);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({1, 1, 2}, {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}});
    test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    test({0, 1}, {{0, 1}, {1, 0}});
    test({1}, {{1}});
    return 0;
}
