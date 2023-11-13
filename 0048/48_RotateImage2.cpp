#include "../inc.h"

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), x0 = 0, x1 = n - 1, y0 = 0, y1 = n - 1, x, y, tmp;
        while (x0 <= x1 && y0 <= y1) {
            x = x0, y = y0;
            /*
            这个题硬转的话还是有点难度的，需要一定的空间想像力，最好是画图把坐标标出来，就简单了
            . . . . . .
            . . . a . .   a => (x, y)
            . d . . . .   d => (n - y - 1, x)
            . . . . b .   b => (y, n - x - 1)
            . . c . . .   c => (n - x - 1, n - y - 1)
            . . . . . .
            */
            while (y < y1) {
                tmp = matrix[x][y];
                matrix[x][y] = matrix[n - y - 1][x];
                matrix[n - y - 1][x] = matrix[n - x - 1][n - y - 1];
                matrix[n - x - 1][n - y - 1] = matrix[y][n - x - 1];
                matrix[y][n - x - 1] = tmp;
                // 下面转反了
                // tmp = matrix[x][y];
                // matrix[x][y] = matrix[y][n - x - 1];
                // matrix[y][n - x - 1] = matrix[n - x - 1][n - y - 1];
                // matrix[n - x - 1][n - y - 1] = matrix[n - y - 1][x];
                // matrix[n - y - 1][x] = tmp;
                ++y;
            }

            ++x0, ++y0, --x1, --y1;
        }
    }
};

void test(vector<vector<int>>&& matrix, const vector<vector<int>>& expect) {
    save4print(matrix);
    Solution so;
    so.rotate(matrix);
    assert_eq_ret(expect, matrix);
}

int main() {
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});
    test({{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
         {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}});
    return 0;
}