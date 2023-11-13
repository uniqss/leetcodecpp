#include "../inc.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

void test(int m, int n, int expect){
    save4print(m, n);
    assert_eq_ret(expect, Solution().uniquePaths(m, n));
}

int main(){
    test(3, 7, 28);
    test(3, 2, 3);
    return 0;
}