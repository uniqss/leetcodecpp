#include "../inc.h"

// 中文官方题解1 据说cpp会超，太不科学了，java和go不会超

class Solution {
   public:
    int jump(vector<int>& nums) {
        int pos = nums.size() - 1;
        int steps = 0;
        while (pos > 0) {
            for (int i = 0; i < pos; ++i) {
                if (i + nums[i] >= pos) {
                    pos = i;
                    ++steps;
                    break;
                }
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
