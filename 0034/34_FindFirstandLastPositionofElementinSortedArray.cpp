#include "../inc.h"

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {}
};

void test(vector<int>&& nums, int target, const vector<int>& expect) {
    save4print(nums, target);
    assert_eq_ret(expect, Solution().searchRange(nums, target));
}

int main() {
    test({5, 7, 7, 8, 8, 10}, 8, {3, 4});
    test({5, 7, 7, 8, 8, 10}, 6, {-1, -1});
    test({}, 0, {-1, -1});
    return 0;
}