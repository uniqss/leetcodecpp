#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mini = 0, maxi = 0, ret = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[maxi]) {
                maxi = i;
                ret = max(ret, prices[maxi] - prices[mini]);
            } else if (prices[i] < prices[mini]) {
                maxi = i;
                mini = i;
            }
        }
        return ret;
    }
};

void test(vector<int>&& prices, int expect) {
    save4print(prices);
    assert_eq_ret(expect, Solution().maxProfit(prices));
}

int main() {
    test({7, 1, 5, 3, 6, 4}, 5);
    test({1, 2}, 1);
    test({7, 6, 4, 3, 1}, 0);
    return 0;
}
