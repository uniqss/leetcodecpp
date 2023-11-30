#include "../inc.h"

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ret = 0, count;
        for (int i = 0; i < 32; ++i) {
            count = 0;
            for (int n : nums)
                if ((n >> i) & 1) ++count;
            if (count % 3 == 1) ret |= (1 << i);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().singleNumber(nums));
}

int main() {
    test({2, 2, 3, 2}, 3);
    test({0, 1, 0, 1, 0, 1, 99}, 99);
    return 0;
}
