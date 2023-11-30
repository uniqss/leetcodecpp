#include "../inc.h"

/*
算是自己硬刚过的吧，但是只有5%的cpu太low了
*/
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dpx(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    dpx[i][j] = 0;
                } else {
                    dpx[i][j] = dpx[i - 1][j] + 1;
                    int maxx = dpx[i][j];
                    int y = j;
                    while (y >= 0 && dpx[i][y] > 0) {
                        maxx = min(maxx, dpx[i][y]);
                        int minxy = min(maxx, (j - y + 1));
                        ret = max(ret, minxy * minxy);
                        --y;
                    }
                }
            }
        }
        return ret;
    }
};

void test(vector<vector<string>>&& matrix, int expect) {
    save4print(matrix);
    auto m = vvs2vvc(matrix);
    assert_eq_ret(expect, Solution().maximalSquare(m));
}

int main() {
    test({{"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}},
         4);
    test({{"0", "1"}, {"1", "0"}}, 1);
    test({{"0"}}, 0);
    return 0;
}
