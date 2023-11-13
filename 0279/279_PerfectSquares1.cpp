#include "../inc.h"

/*
这样就把这个问题和换零钱的问题归并了，先把 i * i <= n 整理成零钱，去找n，算法一致
*/
class Solution {
   public:
    int numSquares(int n) {
        vector<int> dict;
        int i = 1, square = 1;
        while (square <= n) {
            square = i * i;
            dict.emplace_back(square);
            ++i;
        }
        int vmax = n + 1;
        vector<int> dp(n + 1, vmax);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int s : dict) {
                if (s <= i) {
                    dp[i] = min(dp[i], dp[i - s] + 1);
                } else {
                    break;
                }
            }
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