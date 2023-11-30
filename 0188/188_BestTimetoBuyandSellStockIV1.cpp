#include "../inc.h"

// 精巧，有一堆证明
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = min(k, n);
        vector<int> buy(k + 1, -prices[0]), sell(k + 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};

void test(int k, vector<int>&& prices, int expect) {
    save4print(k, prices);
    assert_eq_ret(expect, Solution().maxProfit(k, prices));
}

int main() {
    test(2, {2, 4, 1}, 2);
    test(2, {3, 2, 6, 5, 0, 3}, 7);
    return 0;
}
