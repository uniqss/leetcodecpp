#include "../inc/inc.h"

// 稍微优化了一丢丢，i找到了j一定找的到，而且一定在i的右侧。其实不优化也可

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > i && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

void test(vector<int>&& nums, vector<int>&& expect) {
    Solution so;
    vector<int> nums_saved = nums;

    so.nextPermutation(nums);
    if (nums == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums_saved);
        print(expect);
        print(nums);
    }
}

int main() {
    test({1, 1}, {1, 1});
    test({1, 5, 1}, {5, 1, 1});
    test({3, 2, 1}, {1, 2, 3});
    test({3, 1, 2}, {3, 2, 1});
    test({2, 3, 1}, {3, 1, 2});
    test({1, 2, 3}, {1, 3, 2});
    test({1, 1, 5}, {1, 5, 1});
    return 0;
}
