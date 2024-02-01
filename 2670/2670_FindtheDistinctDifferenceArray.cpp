#include "../inc.h"

class Solution {
   public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {}
};


void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().distinctDifferenceArray(nums));
}
int main() {
    test({1, 2, 3, 4, 5}, {-3, -1, 1, 3, 5});
    test({3, 2, 3, 4, 2}, {-2, -1, 0, 2, 3});
    return 0;
}