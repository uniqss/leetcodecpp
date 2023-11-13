#include "../inc.h"

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {}
};

void test(vector<int>&& nums, vector<int>&& expect) {
    save4print(nums);
    Solution().nextPermutation(nums);
    assert_eq_ret(expect, nums);
}

int main() {
    test({2, 3, 1, 3, 3}, {2, 3, 3, 1, 3});
    test({1, 1}, {1, 1});
    test({1, 5, 1}, {5, 1, 1});
    test({3, 2, 1}, {1, 2, 3});
    test({3, 1, 2}, {3, 2, 1});
    test({2, 3, 1}, {3, 1, 2});
    test({1, 2, 3}, {1, 3, 2});
    test({1, 1, 5}, {1, 5, 1});
    return 0;
}
