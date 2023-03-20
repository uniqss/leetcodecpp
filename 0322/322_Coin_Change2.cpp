#include "../inc/inc.h"

// 参考官方的那个js代码，初始化成 infinity， 一个 for 循环，最后返回才判定一下
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != INT_MAX) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
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
