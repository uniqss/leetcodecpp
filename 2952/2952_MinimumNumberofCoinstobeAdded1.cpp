#include "../inc.h"

// 应该是能解，但是会超时，被之前的coin思路的dp给陷死了无法自拔
class Solution {
   public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size(), ret = 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        sort(coins.begin(), coins.end());
        for (int c : coins) {
            if (c > target) break;
            for (int j = target; j >= c; --j) {
                if (dp[j] == 0 && dp[j - c] > 0) dp[j] = 1;
            }
        }
        int next = 1;
        while (true) {
            while (next <= target && dp[next] != 0) ++next;
            if (next > target) break;
            ++ret;
            for (int j = target; j >= next; --j) {
                if (dp[j] == 0 && dp[j - next] > 0) dp[j] = 1;
            }
        }

        return ret;
    }
};

void test(vector<int>&& coins, int target, int expect) {
    save4print(coins, target);
    assert_eq_ret(expect, Solution().minimumAddedCoins(coins, target));
}

int main() {
    test({1, 4, 10}, 19, 2);
    test({1, 4, 10, 5, 7, 19}, 19, 1);
    test({1, 1, 1}, 20, 3);
    return 0;
}
