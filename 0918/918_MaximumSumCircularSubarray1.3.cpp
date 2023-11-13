#include "../inc.h"

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int pre = nums[0], ret = nums[0], n = nums.size(), sl = 0;
        vector<int> maxl(n, INT_MIN);
        for (int i = 1; i < n; ++i) {
            pre = max(pre + nums[i], nums[i]);
            ret = max(ret, pre);
            sl += nums[i - 1];
            maxl[i] = max(sl, maxl[i - 1]);
        }
        int maxr = INT_MIN, sr = 0;
        for (int i = n - 2; i > 0; --i) {
            sr +=  nums[i + 1];
            maxr = max(sr, maxr);
            ret = max(ret, maxr + maxl[i]);
        }
        return ret;
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
