#include "../inc.h"

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int nsize = nums.size();
        if (nsize < 3) return false;
        int l = nums[0], r = INT_MAX;
        for (int i = 1; i < nsize; ++i) {
            if (nums[i] <= l) {
                l = nums[i];
            } else if (nums[i] <= r) {
                r = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

void test(vector<int>&& nums, bool expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().increasingTriplet(nums));
}

int main() {
    test({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
         false);
    test({20, 100, 10, 12, 5, 13}, true);
    test({2, 4, -2, -3}, false);
    test({1, 2, 3, 4, 5}, true);
    test({5, 4, 3, 2, 1}, false);
    test({2, 1, 5, 0, 4, 6}, true);
    return 0;
}
