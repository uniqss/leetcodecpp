#include "../inc.h"

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        /*
        当前最大收获=打劫当前+不打劫当前
        打劫当前=前一家不打劫+当前
        不打劫当前=前一家不打劫 | 前一家打劫
        文字一写，逻辑立刻清晰了
        */
        vector<int> dpnorob(n + 1);
        vector<int> dprob(n + 1);
        for (int i = 0; i < n; ++i) {
            dprob[i + 1] = dpnorob[i] + nums[i];
            dpnorob[i + 1] =  max(dpnorob[i], dprob[i]);
            ret = max(ret, dprob[i + 1]);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().rob(nums));
}

int main() {
    test({0}, 0);
    test({1, 2, 3, 1}, 4);
    test({2, 7, 9, 3, 1}, 12);
    test({2, 1, 1, 2}, 4);
    return 0;
}
