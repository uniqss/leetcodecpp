#include "../inc.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // m, n   s[i] t[j]
        /*
        dp三步曲：
        1.建立N维数组dp[m + 1][n + 1]
        2.边界值dp[0][j] = 0   dp[i][0] = 0
        3.递推规则得到状态转移方程
            s[i - 1] == t[j - 1]   dp[i][j] = dp[i - 1][j - 1] + 1 相等，前一个加1即可
            s[i - 1] != t[j - 1]   dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) 上左最大
        */
       const auto& s = text1, &t = text2;
       int m = s.size(), n = t.size();
       vector<vector<int>> dp(m + 1, vector<int>(n + 1));
       for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
       }
       return dp[m][n];
    }
};

void test(string text1, string text2, int expect) {
    Solution so;
    auto ret = so.longestCommonSubsequence(text1, text2);
    assert_eq_ret(expect, ret);
    print(text1);
    print(text2);
}

int main(){
    test("bsb", "b", 1);
    test("bsbininm", "jmjkbkjkv", 1);
    test("abcde", "ace", 3);
    test("abc", "abc", 3);
    test("abc", "def", 0);
    return 0;
}
