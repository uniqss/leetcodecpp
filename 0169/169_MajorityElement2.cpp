#include "../inc.h"

/*
Boyer-Moore投票算法，这个方法取巧有点过，不推荐，项目中用到建议还是hash的方法，不过思路很新奇，思路是把最多值和非最多值区分开
*/
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int ret = 0;
        int count = 0;
        for (int num : nums) {
            if (num == ret) {
                ++count;
            } else if (--count < 0) {
                ret = num;
                count = 1;
            }
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expected) {
    save4print(nums);
    assert_eq_ret(expected, Solution().majorityElement(nums));
}

int main() {
    test({3, 2, 3}, 3);
    test({2, 2, 1, 1, 1, 2, 2}, 2);
    return 0;
}
