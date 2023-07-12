#include "../inc.h"

/*
2的真实原貌，没优化前的

把[0...i-1]视为黑盒，记为dp[i - 1]，有两种可能：
里面有奇数个结算点，记为dp[i - 1][0]
里面有偶数个结算点，记为dp[i - 1][1]
当i出现
里面有奇数个结算点：
    选择i作为结算点。原偶数个结算点，最后一个奇数结算点的值直接加上去 dp[i - 1][1] + nums[i]
    原奇数个结算点 dp[i - 1][0]
里面有偶数个结算点：
    选择i作为结算点。原奇数个结算点，减去最后一个结算点的值 dp[i - 1][0] - nums[i]
    原偶数个结算点 dp[i - 1][1]

*/
class Solution {
   public:
    long long maxAlternatingSum(vector<int>& nums) {
        int nsize = nums.size();
        vector<vector<long long>> dp(nsize, vector<long long>(2, 0));
        dp[0][0] = nums[0];
        for (int i = 1; i < nsize; ++i) {
            dp[i][0] = max(dp[i - 1][1] + nums[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] - nums[i], dp[i - 1][1]);
        }
        return dp[nsize - 1][0];
    }
};

void test(vector<int>&& nums, long long expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.maxAlternatingSum(nums);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok");
        print(nums_param);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({4, 2, 5, 3}, 7);
    test({5, 6, 7, 8}, 8);
    test({6, 2, 1, 2, 4, 5}, 10);
    return 0;
}
