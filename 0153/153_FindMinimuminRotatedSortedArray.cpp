#include "../inc.h"

class Solution {
   public:
    int findMin(vector<int>& nums) {}
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().findMin(nums));
}

int main() {
    test({3, 1, 2}, 1);
    test({2, 1}, 1);
    test({3, 4, 5, 1, 2}, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0);
    test({11, 13, 15, 17}, 11);
    return 0;
}