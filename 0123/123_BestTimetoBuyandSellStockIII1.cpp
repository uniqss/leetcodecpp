#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ret = 0;
        vector<int> dpl(n), dpr(n);
        int low = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < low) {
                low = prices[i];
                dpl[i] = dpl[i - 1];
            } else {
                dpl[i] = max(dpl[i - 1], prices[i] - low);
            }
        }
        ret = max(ret, dpl[n - 1]);
        int high = prices[n - 1];
        for (int i = n - 2; i > 0; --i) {
            if (prices[i] > high) {
                high = prices[i];
                dpr[i] = dpr[i + 1];
            } else {
                dpr[i] = max(dpr[i + 1], high - prices[i]);
            }
            ret = max(dpl[i - 1] + dpr[i], ret);
        }
        return ret;
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
