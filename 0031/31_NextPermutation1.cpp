#include "../inc.h"

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        size_t nsize = nums.size();
        int pos = -1;
        for (size_t i = nsize - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                pos = i - 1;
                break;
            }
        }
        if (pos == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int right_pos = -1;
        int right_val = INT_MAX;
        for (size_t i = nsize - 1; i > (size_t)pos; --i) {
            if (nums[i] > nums[pos] && nums[i] < right_val) {
                right_val = nums[i];
                right_pos = i;
            }
        }
        swap(nums[pos], nums[right_pos]);
        if (pos < (int)nsize - 2) {
            std::sort(nums.begin() + pos + 1, nums.end());
        }
    }
};

void test(vector<int>&& nums, vector<int>&& expect) {
    save4print(nums);
    Solution().nextPermutation(nums);
    assert_eq_ret(expect, nums);
}

int main() {
    test({1, 2, 3}, {1, 3, 2});
    test({3, 2, 1}, {1, 2, 3});
    test({1, 1, 5}, {1, 5, 1});
    return 0;
}
