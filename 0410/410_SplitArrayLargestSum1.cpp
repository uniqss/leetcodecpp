#include "../inc.h"

using LL = long long;
class Solution {
   public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n + 1);
        /*
        C(n,k)问题
        f[i][j]表示【前i个数分成j段】largest sum
        注意f[0][0]=0,i是1-indexed不是0indexed
        f[i][j] 把i定住，把j定住，去枚举k从[0,i-1]。意义：考虑i个数分成j段的所有可能性
        x的取值范围：[j-1, i)
        0 1 ... ... i ... 分j段
        x ... . ... i ... x=0
        0 ... ... x i ... x=i-1
        去枚举 x，从0到 x - 1分成j-1段，[x+1,i-1]单独做一段
        左边[0,x]要能分成j-1段，所以x要>=j-1，一段至少要占一个数
        用前缀和优化sum
        f[i,j] = max(f[i,j-1], f[x][j-1]+sum(x+1,i))
        */
        for (int i = 1; i <= n; ++i) presum[i] = presum[i - 1] + nums[i - 1];
        vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(k, i); ++j) {
                for (int x = j - 1; x < i; ++x) {
                    dp[i][j] = min(dp[i][j], max(dp[i][x], (LL)(presum[i] - presum[x])));
                }
            }
        }
        return dp[n][k];
    }
};

void test(vector<int>&& nums, int k, int expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().splitArray(nums, k));
}

int main() {
    test({7, 2, 5, 10, 8}, 2, 18);
    test({1, 2, 3, 4, 5}, 2, 9);
    return 0;
}