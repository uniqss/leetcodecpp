#include "../inc.h"

// 准确的说，这是在2的基础上的一个更高维度的抽象
// 也就是因为有了这个抽象，可以推广到n
// 更精准地看透了事物的本质
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(2 + 1, -prices[0]), sell(2 + 1);
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= 2; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[2];
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
