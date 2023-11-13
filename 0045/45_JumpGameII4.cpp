#include "../inc.h"

// 中文官方题解2 稍微精简一点

class Solution {
   public:
    int jump(vector<int>& nums) {
        int maxpos = 0, n = nums.size(), end = 0, steps = 0;
        for (int i = 0; i < n - 1; ++i) {
            maxpos = max(maxpos, i + nums[i]);
            if (i == end) {
                ++steps;
                end = maxpos;
            }
        }

        return steps;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().jump(nums));
}

int main() {
    test({2, 3, 1, 1, 4}, 2);
    test({2, 3, 0, 1, 4}, 2);
    return 0;
}
