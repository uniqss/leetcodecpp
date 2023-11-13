#include "../inc.h"

/*
这个方法简直太聪明了，既然一步不能砍掉一半，那就砍掉m或者n，也是非常快速的
o(m + n)
二分思路还是要抓一下整个数据的中心，这里不能以(x0 + x1) / 2, (y0 + y1) / 2作为中心，也就是图形的中心。
*/
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target)
                --y;
            else
                ++x;
        }
        return false;
    }
};

void test(vector<vector<int>>&& matrix, int target, bool expect) {
    auto p1 = matrix;
    Solution so;
    auto ret = so.searchMatrix(matrix, target);
    assert_eq_ret(expect, ret);
    print(p1);
    print(target);
}

int main() {
    test({{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 5,
         true);
    test({{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}, 20,
         false);
    return 0;
}
