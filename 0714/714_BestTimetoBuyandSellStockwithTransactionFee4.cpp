#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = prices[0] + fee, profit = 0, n = prices.size();
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            } else if (prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
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