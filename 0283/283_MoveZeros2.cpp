#include "../inc/inc.h"

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        size_t valid = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[valid], nums[i]);
                ++valid;
            }
        }
    }
};

void test(vector<int>&& nums, const vector<int>& expect) {
    Solution so;
    vector<int> nums_param = nums;
    so.moveZeroes(nums);
    if (nums == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums_param);
        print(expect);
        print(nums);
        print();
    }
}

int main() {
    test({1, 0, 2, 3, 0, 4}, {1, 2, 3, 4, 0, 0});
    test({0, 1, 0, 0, 5, 0}, {1, 5, 0, 0, 0, 0});

    return 0;
}
