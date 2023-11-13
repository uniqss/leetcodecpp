#include "../inc.h"

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int pre = nums[0], ret = nums[0], n = nums.size();
        vector<int> dpl(n, 0);
        int suml = nums[0];
        dpl[0] = suml;
        for (int i = 1; i < n; ++i) {
            pre = max(nums[i], pre + nums[i]);
            ret = max(ret, pre);
            suml += nums[i];
            dpl[i] = max(dpl[i - 1], suml);
        }
        int dpr = nums[n - 1];
        int sumr = nums[n - 1];
        for (int j = n - 2; j > 0; --j) {
            sumr += nums[j];
            ret = max(ret, dpl[j - 1] + dpr);
            dpr = max(dpr, sumr);
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
