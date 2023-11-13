#include "../inc.h"

/*
中文官方解法，颜值确实比我的高
*/
class Solution {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int dpi = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                dpi = min(dpi, dp[i - j * j] + 1);
            }
            dp[i] = dpi;
        }
        return dp[n];
    }
};

void test(int n, int expect) {
    Solution so;
    auto ret = so.numSquares(n);
    assert_eq_ret(expect, ret);
    print(n);
}

int main() {
    test(12, 3);
    test(13, 2);
    test(1, 1);
    test(2, 2);
    test(3, 3);
    test(4, 1);
    return 0;
}