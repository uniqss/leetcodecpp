#include "../inc.h"

class Solution {
   public:
    int longestSubsequence(vector<int>& nums, int d) {
        /*
        以dp[i]表示以下标i结尾的最长等差子序列长度，取所有dp[i]的最大值，即为答案
        dp[i]表示i结尾最大的等差子序列长度，在i左侧肯定有j，arr[j] = arr[i] - d.
        因从左向右遍历，对于两个相同的元素，下标大的值dp[i]不会小于下标小的值dp[j]
            (示例：假设d=2,前面有3,5,7，再遇到无论3还是5还是7，dp[i]一定>=dp[j]不存在小于)
        j满足：j < i 且 arr[j] = arr[i] - d的所有下标的最大值。故有dp转移方程(j = i - d)：
            dp[i] = dp[j] + 1
        */
        unordered_map<int, int> dp;
        int ret = 0;
        for (int num : nums) {
            auto it = dp.find(num - d);
            if (it == dp.end())
                dp[num] = 1;
            else
                dp[num] = it->second + 1;
            ret = max(ret, dp[num]);
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
