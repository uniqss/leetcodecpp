#include "../inc.h"

/*
这里有个逻辑推理： [0...x...y...n-1] 假设[0,x] + [y,n-1]为最大应该返回的值，则[x,y]一定是全域最小和
证明：假设有z满足[0...z...x...y...n-1]使得 [z,y] < [x,y] 则[0,z] > [0,x] 则[0,z] + [y,n-1] 才是应该的返回值。[0,x]与[y,n-1]数学上是对称关系，同理证略
所以就有了sum-smin
*/
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), premax = nums[0], premin = nums[0], smax = nums[0], smin = nums[0], sum = nums[0];
        for (int i = 1; i < n; ++i) {
            premax = max(premax + nums[i], nums[i]);
            smax = max(smax, premax);
            premin = min(premin + nums[i], nums[i]);
            smin = min(smin, premin);
            sum += nums[i];
        }
        return smax < 0 ? smax : max(smax, sum - smin);
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().maxSubarraySumCircular(nums));
}

int main() {
    test({4, 4, -9, 2, 1, 7, 5}, 23);
    test({2, -2, 2, 7, 8, 0}, 19);
    test({-2, 4, -5, 4, -5, 9, 4}, 15);
    test({1, -6, -7, 4}, 5);
    test({9, -4, -7, 9}, 18);
    test({3, -1, 2, -1}, 4);
    test({1, -2, 3, -2}, 3);
    test({5, -3, 5}, 10);
    test({-3, -2, -3}, -2);
    return 0;
}
