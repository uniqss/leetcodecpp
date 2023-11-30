#include "../inc.h"

// 非常经典的解法，中文官方有证明过程
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};

void test(vector<int>&& prices, int expect) {
    save4print(prices);
    assert_eq_ret(expect, Solution().maxProfit(prices));
}

int main() {
    test({3, 3, 5, 0, 0, 3, 1, 4}, 6);
    test({1, 2, 3, 4, 5}, 4);
    test({7, 6, 4, 3, 1}, 0);
    return 0;
}
