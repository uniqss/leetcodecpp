#include "../inc.h"

// TLE
class Solution {
   public:
    int longestIdealString(string s, int k) {
        int n = s.size(), ret = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (abs(s[i] - s[j]) <= k) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for (int i = 0; i < n; ++i) ret = max(ret, dp[i]);
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
