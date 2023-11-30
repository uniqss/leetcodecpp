#include "../inc.h"

// 正确，但会超出内存限制，必须减dp内存开销
class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int64_t ret = 0, mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (j == i) {
                    dp[i][j] = arr[i];
                } else {
                    dp[i][j] = min(dp[i][j - 1], arr[j]);
                }
                ret += dp[i][j];
                ret %= mod;
            }
        }
        return (int)ret;
    }
};

void test(vector<int>&& arr, int expect) {
    save4print(arr);
    assert_eq_ret(expect, Solution().sumSubarrayMins(arr));
}

int main() {
    test({3, 1, 2, 4}, 17);
    test({11, 81, 94, 43, 3}, 444);
    return 0;
}
