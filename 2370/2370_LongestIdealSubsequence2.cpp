#include "../inc.h"

/*
思路：
当我们思考到某个字符为结尾的情况时，大分为两种可能
    最长串是以该字符结尾，也就是选当前
    最长串不以该字符结尾，也就是不选当前
所以对于某个位置的字符，状态为 (i, s[i])。定义二维状态dp[i][s[i]], i的范围[0, n), s[i]的范围[0, 25]
状态转移：
    选当前位时，dp[i][j] = dp[i - 1][k] + 1, 枚举k的范围为[max(s[i] - k, 0), min(s[i] + k, 25)]
    不选当前位时，d[i][j] = dp[i - 1][j]

这题有两点值得品味：
    一，当我们的问题中每位可选可不选时，我们为了把问题具象，应该是该位选和不选分类讨论，并以选时的状态，固定住往前思考问题，不需要去中间一段一段思考问题并拼接结果。
        当我们的问题中不存在可跳过的位时，我们为了把问题具象，应该是从第一位开始往后思考问题，不需去中间一段一段思考问题并拼接结果。
    二，非常经典又非常常见的dp降维，减少空间复杂度
*/
class Solution {
   public:
    int longestIdealString(string s, int k) {
        int ret = 0;
        vector<int> f(26);
        for (char c : s) {
            c -= 'a';
            for (int i = max(c - k, 0); i <= min(c + k, 25); ++i) {
                f[c] = max(f[c], f[i]);
            }
            ++f[c];
        }

        for (int dpi : f) ret = max(ret, dpi);
        return ret;
    }
};

void test(string&& s, int k, int expect) {
    save4print(s, k);
    assert_eq_ret(expect, Solution().longestIdealString(s, k));
}

int main() {
    test("acfgbd", 2, 4);
    test("abcd", 3, 4);
    test("lkpkxcigcs", 6, 7);
    return 0;
}
