#include "../inc.h"

// 这不就是杨辉三角嘛  easy
// 脑海里保持那幅三角的图就行了，注意把三角往左推一下，变成直角三角形，左边是个垂直的竖线
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), ret = INT_MAX;
        vector<int> dp(n, INT_MIN);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            const vector<int>& currlayer = triangle[i];
            dp[i] = dp[i - 1] + currlayer[i];
            for (int j = i - 1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j - 1]) + currlayer[j];
            }
            dp[0] += currlayer[0];
        }
        for (int dpi : dp) ret = min(ret, dpi);
        return ret;
    }
};

void test(vector<vector<int>>&& triangle, int expect) {
    save4print(triangle);
    assert_eq_ret(expect, Solution().minimumTotal(triangle));
}

int main() {
    test({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11);
    test({{-10}}, -10);
    return 0;
}
