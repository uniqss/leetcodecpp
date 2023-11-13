#include "../inc.h"

/*
很多边界条件还是需要注意的，这个内存省的一点也不省心。。。项目中不建议这样用
*/
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool x0 = false, y0 = false;
        for (int x = 0; x < m; ++x)
            if (matrix[x][0] == 0) x0 = true;
        for (int y = 0; y < n; ++y)
            if (matrix[0][y] == 0) y0 = true;
        for (int x = 0; x < m; ++x)
            for (int y = 0; y < n; ++y)
                if (matrix[x][y] == 0) matrix[x][0] = 0, matrix[0][y] = 0;
        for (int x = 1; x < m; ++x)
            for (int y = 1; y < n; ++y)
                if (matrix[x][0] == 0 || matrix[0][y] == 0) matrix[x][y] = 0;
        if (x0)
            for (int x = 0; x < m; ++x) matrix[x][0] = 0;
        if (y0)
            for (int y = 0; y < n; ++y) matrix[0][y] = 0;
    }
};

void test(vector<vector<int>>&& matrix, const vector<vector<int>>& expect) {
    save4print(matrix);
    Solution().setZeroes(matrix);
    assert_eq_ret(expect, matrix);
}

int main() {
    test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});
    test({{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}});
    return 0;
}
