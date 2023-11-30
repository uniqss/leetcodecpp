#include "../inc.h"

/*
我把它叫做空间折叠法，有点类似等差数列等比数列计算和的思路，想办法让它错一位，折叠一位
左乘：
    ret[0] = 1
    ret[i] = ret[i - 1] * nums[i - 1]
左乘完以后，ret已经是一个所有左侧元素的乘积

不考虑空间的情况下，对称一下，再开一下ret2记一下 ret[i] = ret[i + 1] * nums[i + 1]右边的乘积，再乘一下即可

考虑空间的情况下，这里类似dp在递推斐波拉契数列的时候，一维数组如果后续用的都只依赖前1位时，可以用一个数来记并递推
plusr = 1;
从右往左
ret[i] *= plusr;
plusr *= nums[i];
*/

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto nsize = nums.size();
        vector<int> ret(nsize, 1);
        for (int i = 1; i < nsize; ++i) {
            ret[i] = ret[i - 1] * nums[i - 1];
        }
        int plusr = 1;
        for (int i = nsize - 1; i >= 0; --i) {
            ret[i] *= plusr;
            plusr *= nums[i];
        }

        return ret;
    }
};

void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().productExceptSelf(nums));
}

int main() {
    test({1, 2, 3, 4}, {24, 12, 8, 6});
    test({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});
    return 0;
}
