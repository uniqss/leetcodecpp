#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
        dp[0][0] = 0, dp[0][1] = -prices[0] 买入不计费，卖出才计
        dp[i][0] 交易完后手里没有股票的最大利润的手头现金数
        dp[i][1] 交易完后手里有股票的最大利润的手头现金数，股票不算
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        */
        int n = prices.size(), ret = 0;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

void test(vector<int>&& prices, int fee, int expect) {
    auto param1 = prices;
    Solution so;
    auto ret = so.maxProfit(prices, fee);
    assert_eq_ret(expect, ret);
    print(param1);
    print(fee);
}

int main() {
    test({1, 3, 2, 8, 4, 9}, 2, 8);
    test({1, 3, 7, 5, 10, 3}, 3, 6);
    return 0;
}