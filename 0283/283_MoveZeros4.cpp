#include "../inc.h"

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int nsize = nums.size(), valid = 0;
        for (int& n : nums) {
            if (n != 0) swap(nums[valid++], n);
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
    test({73348, 66106, -85359, 53996, 18849, -6590, -53381, -86613, -41065, 83457, 0},
         {73348, 66106, -85359, 53996, 18849, -6590, -53381, -86613, -41065, 83457, 0});
    test({1, 0, 2, 3, 0, 4}, {1, 2, 3, 4, 0, 0});
    test({0, 1, 0, 0, 5, 0}, {1, 5, 0, 0, 0, 0});

    return 0;
}
