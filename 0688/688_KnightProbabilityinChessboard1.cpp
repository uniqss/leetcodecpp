#include "../inc.h"

/*
正推思路：in：落在里面的一个棋盘的dp记录/out：落在外面的统一记录
问题：在正推的过程中，for r c 的时候，八角会影响到后面的数值。
    我们用模拟移动的思路，对整个棋盘上所有位置记录，每次遍历整个棋盘，得到下一步移动能落到棋盘内的下一个棋盘局面值。
    所以也需要k+1块棋盘
    out的问题：out一次以后，下一次没法继续算out，所以直接拿std::pow(8, k)   8^k
    会溢出，改用int64。依然会溢出。。。所以只能用double的方案，其实是忽略了一定的精度

正推整型的思路不可行

*/

class Solution {
   public:
    double knightProbability(int n, int k, int row, int column) {
        // 1 <= n <= 25
        if (k == 0) return 1.00;
        vector<vector<vector<int64_t>>> dict(k + 1, vector<vector<int64_t>>(n, vector<int64_t>(n, 0)));
        dict[0][row][column] = 1;
        for (int i = 1; i <= k; ++i) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    auto vprev = dict[i - 1][r][c];
                    if (vprev > 0) {
                        if (r >= 1 && c >= 2) dict[i][r - 1][c - 2] += vprev;
                        if (r >= 2 && c >= 1) dict[i][r - 2][c - 1] += vprev;
                        if (r >= 2 && c <= n - 2) dict[i][r - 2][c + 1] += vprev;
                        if (r >= 1 && c <= n - 3) dict[i][r - 1][c + 2] += vprev;
                        if (r <= n - 2 && c <= n - 3) dict[i][r + 1][c + 2] += vprev;
                        if (r <= n - 3 && c <= n - 2) dict[i][r + 2][c + 1] += vprev;
                        if (r <= n - 2 && c >= 2) dict[i][r + 1][c - 2] += vprev;
                        if (r <= n - 3 && c >= 1) dict[i][r + 2][c - 1] += vprev;
                    }
                }
            }
        }
        int64_t in = 0;
        for (auto r : dict[k]) {
            for (auto c : r) {
                in += c;
            }
        }
        return (double)in / (double(std::pow(8, k)));
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
