#include "../inc.h"

class Solution {
   public:
    int longestSubsequence(vector<int>& nums, int d) {
        int ret = 1;
        const int offset = 20000;
        vector<int> dp(40001, 0);
        for (int num : nums) {
            if (dp[num + offset - d] == 0) {
                dp[num + offset] = 1;
            } else {
                dp[num + offset] = dp[num + offset - d] + 1;
                ret = max(dp[num + offset], ret);
            }
        }
        return ret;
    }
};

void test(vector<int>&& arr, int difference, int expect) {
    auto arr_param = arr;
    Solution so;
    auto ret = so.longestSubsequence(arr, difference);
    assert_eq_ret(expect, ret);
    print(arr_param);
    print(difference);
}

int main() {
    test({1, 2, 3, 4}, 1, 4);
    test({1, 3, 5, 7}, 1, 1);
    test({1, 5, 7, 8, 5, 3, 4, 2, 1}, -2, 4);
    return 0;
}
