#include "../inc.h"

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxpos = 0;
        for (int i = 0; i < n && i <= maxpos; ++i) {
            maxpos = max(maxpos, i + nums[i]);
            if (maxpos >= n) return true;
        }
        return maxpos >= n - 1;
    }
};

void test(vector<int>&& nums, bool expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().canJump(nums));
}

int main() {
    test({0}, true);
    test({0, 2, 3}, false);
    test({1, 2}, true);
    test({2, 3, 1, 1, 4}, true);
    test({3, 2, 1, 0, 4}, false);
    return 0;
}
