#include "../inc.h"

class Solution {
   public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0)));
        vector<pair<int, int>> offsets = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        int nr, nc;
        for (int i = 0; i <= k; ++i) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (i == 0) {
                        dp[i][r][c] = 1;
                    } else {
                        for (auto offset : offsets) {
                            nr = r + offset.first, nc = c + offset.second;
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                                dp[i][nr][nc] += dp[i - 1][r][c] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};

void test(int n, int k, int row, int column, double expect) {
    Solution so;
    auto ret = so.knightProbability(n, k, row, column);
    assert_eq_ret(expect, ret);
    print(n);
    print(k);
    print(row);
    print(column);
}

int main() {
    test(8, 30, 6, 4, 0.000190526);
    test(3, 2, 0, 0, 0.06250);
    test(1, 0, 0, 0, 1.00000);
    return 0;
}
