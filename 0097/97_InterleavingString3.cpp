#include "../inc.h"

// 之所以一直把这题pin住是因为当时翻车的思路离谱的比较严重。整理简记一下
// 当时的思路是暴力，第1个位置有选A选B两种可能，第2个位置又在此基础上有2种可能，这样一算计算机的存储是不够用的
// 类似的思路好像之前在哪个dp题里也翻过车，这里得从切分数组的思路入手，因为AB都是顺序选，
// 想象AB分别有m+1, n+1个切分点，这样一想就是dp了
class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if ((i > 0 && dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) ||
                    (j > 0 && dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]))
                    dp[i][j] = true;
            }
        }
        return dp[m][n];
    }
};

void test(string s1, string s2, string s3, bool expect) {
    save4print(s1, s2, s3);
    assert_eq_ret(expect, Solution().isInterleave(s1, s2, s3));
}

int main() {
    test("", "", "a", false);
    test("aabcc", "dbbca", "aadbbcbcac", true);
    test("aabcc", "dbbca", "aadbbbaccc", false);
    test("", "", "", true);
    return 0;
}
