#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        if (prices.size() <= 1) return ret;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i]) ret += prices[i + 1] - prices[i];
        }
        return ret;
    }
};

void test(vector<int>&& prices, int expect) {
    save4print(prices);
    assert_eq_ret(expect, Solution().maxProfit(prices));
}

int main() {
    test({7, 1, 5, 3, 6, 4}, 7);
    test({7, 6, 4, 3, 1}, 0);
    test({1, 2}, 1);
    return 0;
}
