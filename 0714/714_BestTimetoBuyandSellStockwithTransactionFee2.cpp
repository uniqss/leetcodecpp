#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        */
        int profit_no_stock = 0, profit_with_stock = -prices[0], n = prices.size();
        for (int i = 1; i < n; ++i) {
            int price = prices[i], pre_ns = profit_no_stock, pre_s = profit_with_stock;
            int curr_ns = max(pre_ns, pre_s + price - fee);
            int curr_s = max(pre_s, pre_ns - price);
            profit_no_stock = curr_ns;
            profit_with_stock = curr_s;
        }
        return profit_no_stock;
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