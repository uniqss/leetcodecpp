#include "../inc.h"

// 最正统也是最直白的写法，可优化
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int pre = nums[0], ret = nums[0], n = nums.size();
        for (int i = 1; i < n; ++i) {
            pre = max(nums[i], pre + nums[i]);
            ret = max(ret, pre);
        }
        vector<int> dpl(n, 0);
        int suml = nums[0];
        dpl[0] = suml;
        for (int j = 1; j < n - 1; ++j) {
            suml += nums[j];
            dpl[j] = max(dpl[j - 1], suml);
        }
        vector<int> dpr(n, 0);
        int sumr = nums[n - 1];
        dpr[n - 1] = sumr;
        for (int j = n - 2; j > 0; --j) {
            sumr += nums[j];
            dpr[j] = max(dpr[j + 1], sumr);
        }
        for (int j = 1; j < n - 1; ++j) {
            ret = max(ret, dpl[j - 1] + dpr[j + 1]);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().maxSubarraySumCircular(nums));
}

int main() {
    test({-2, 4, -5, 4, -5, 9, 4}, 15);
    test({1, -6, -7, 4}, 5);
    test({9, -4, -7, 9}, 18);
    test({3, -1, 2, -1}, 4);
    test({1, -2, 3, -2}, 3);
    test({5, -3, 5}, 10);
    test({-3, -2, -3}, -2);
    return 0;
}
