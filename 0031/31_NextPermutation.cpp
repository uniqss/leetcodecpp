#include "../inc/inc.h"

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {}
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
