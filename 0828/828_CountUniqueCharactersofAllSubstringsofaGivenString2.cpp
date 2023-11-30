#include "../inc.h"

class Solution {
   public:
    int uniqueLetterString(string s) {
        int ret = 0, n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<vector<int>>> counts(n, vector<vector<int>>(n, vector<int>(26)));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (j == i) {
                    dp[i][j] = 1;
                    ++counts[i][j][s[i] - 'A'];
                } else if (j > i) {
                    counts[i][j] = counts[i][j - 1];
                    int curr = s[j] - 'A';
                    if (counts[i][j - 1][curr] == 1)
                        dp[i][j] = dp[i][j - 1] - 1;
                    else if (counts[i][j - 1][curr] == 0)
                        dp[i][j] = dp[i][j - 1] + 1;
                    else
                        dp[i][j] = dp[i][j - 1];
                    ++counts[i][j][curr];
                }
                ret += dp[i][j];
            }
        }
        return ret;
    }
};

void test(string s, int expect) {
    save4print(s);
    assert_eq_ret(expect, Solution().uniqueLetterString(s));
}

int main() {
    test("ABC", 10);
    test("ABA", 8);
    test("LEETCODE", 92);
    return 0;
}
