#include "../inc.h"

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        for (int coin : coins) {
            if (coin > amount) break;
            dp[coin] = 1;
        }
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            if (dp[i] > 0) continue;

            int dpmin = INT_MAX;
            for (int coin : coins) {
                if (i > coin && dp[i - coin] > 0) {
                    dpmin = min(dpmin, dp[i - coin] + 1);
                }
            }
            if (dpmin != INT_MAX) dp[i] = dpmin;
        }

        return dp[amount];
    }
};

void test(vector<int>&& coins, int amount, int expect) {
    Solution so;
    auto ret = so.coinChange(coins, amount);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(coins);
        print(amount);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2}, 2, 1);
    test({2147483647}, 2, -1);
    test({1, 2, 5}, 11, 3);
    test({2}, 3, -1);
    test({1}, 0, 0);
    return 0;
}
