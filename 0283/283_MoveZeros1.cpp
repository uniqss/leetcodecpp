#include "inc.h"

/*
三种情况：
非空前置不移 nums[i] != 0 && i == j  ++j
非空移动  nums[i] != 0 && i != j   nums[j] = nums[i], nums[i] = 0, ++j
空不移 nothing

*/
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != j) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                ++j;
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