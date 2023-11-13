#include "../inc.h"

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int x0 = 0, x1 = matrix.size() - 1, x;
        int y0 = 0, y1 = matrix[0].size() - 1, y;
        while (x1 > x0 && y1 > y0) {
            x = x0, y = y0;
            while (y < y1) ret.emplace_back(matrix[x][y]), ++y;
            while (x < x1) ret.emplace_back(matrix[x][y]), ++x;
            while (y > y0) ret.emplace_back(matrix[x][y]), --y;
            while (x > x0) ret.emplace_back(matrix[x][y]), --x;
            ++x0, --x1, ++y0, --y1;
        }
        for (x = x0; x <= x1; ++x) {
            for (y = y0; y <= y1; ++y) {
                ret.emplace_back(matrix[x][y]);
            }
        }

        return ret;
    }
};

void test(vector<vector<int>>&& matrix, const vector<int>& expect) {
    save4print(matrix);
    assert_eq_ret(expect, Solution().spiralOrder(matrix));
}

int main() {
    test({{6, 9, 7}}, {6, 9, 7});
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5});
    test({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7});
    return 0;
}
