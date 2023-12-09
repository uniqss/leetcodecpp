#include "../inc.h"

// 这种题目的推演规律，要记下来。不是记最终结果 有有=无无 有无=无有+无无 无有=有无+无无 无无=全和
// 而是记，推演是按位进行，每位有两个点位，有四种可能。每种可能都可以从前一个中叠加过来
// 这题应该有变种，把弯形变成其他形状，或增减形状。掌握规律的规律，递推出规律，就可dp
class Solution {
   public:
    int numTilings(int n) {
        vector<vector<int64_t>> dp(n, vector<int64_t>(4));
        dp[0][0] = 0;  // 上有下空
        dp[0][1] = 0;  // 上空下有
        dp[0][2] = 1;  // 上空下空
        dp[0][3] = 1;  // 上有下有
        int64_t mod = 1e9 + 7;
        vector<int64_t> pre;
        for (int i = 1; i < n; ++i) {
            pre = dp[i - 1];
            auto& curr = dp[i];
            curr[0] = (pre[2] + pre[1]) % mod;
            curr[1] = (pre[2] + pre[0]) % mod;
            curr[2] = pre[3];
            curr[3] = (pre[0] + pre[1] + pre[2] + pre[3]) % mod;
        }
        return dp[n - 1][3];
    }
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().numTilings(n));
}

int main() {
    test(1, 1);
    test(2, 2);
    test(3, 5);
    test(4, 11);
    return 0;
}
