#include "../inc.h"

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int maxreachable = nums[0] + 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (i >= maxreachable) return false;
            maxreachable = max(maxreachable, i + nums[i] + 1);
        }
        return true;
    }
};

void test(vector<int>&& nums, bool expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().canJump(nums));
}

int main() {
    test({1, 2}, true);
    test({2, 3, 1, 1, 4}, true);
    test({3, 2, 1, 0, 4}, false);
    return 0;
}
