#include "../inc.h"

// 换汤不换药，一个减向左找，一个加往右找，本质上都是填表
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            if (dp[i] != INT_MAX) {
                for (int c : coins) {
                    if (c <= amount && i + c <= amount) {
                        dp[i + c] = min(dp[i + c], dp[i] + 1);
                    } else
                        break;
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

void test(vector<int>&& coins, int amount, int expect) {
    save4print(coins, amount);
    assert_eq_ret(expect, Solution().coinChange(coins, amount));
}

int main() {
    test({1, 2147483647}, 2, 2);
    test({1, 2}, 2, 1);
    test({2147483647}, 2, -1);
    test({1, 2, 5}, 11, 3);
    test({2}, 3, -1);
    test({1}, 0, 0);
    return 0;
}
