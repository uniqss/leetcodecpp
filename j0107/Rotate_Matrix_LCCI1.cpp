#include "../inc.h"

/*
我的写法和作者思路感觉会更近，官方在那搞了一堆乱七八糟的公式。反正O(n^2)是跑不掉的，因为要访问每一个元素。不如我的清爽
以左下角为(0, 0)点，先左右转一下，再沿45度角转一下
*/
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        size_t n = matrix.size();
        for (size_t i = 0; i < n / 2; ++i) {
            for (size_t j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

void test(vector<vector<int>>&& matrix, const vector<vector<int>>& expect) {
    save4print(matrix);
    Solution().rotate(matrix);
    assert_eq_ret(expect, matrix);
}

int main() {
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});

    return 0;
}
