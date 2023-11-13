#include "../inc.h"

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x0 = 0, x1 = matrix.size() - 1, y0 = 0, y1 = matrix[0].size() - 1, x, y, valid = 0;
        vector<int> ret(matrix.size() * matrix[0].size());
        while (x0 <= x1 && y0 <= y1) {
            x = x0, y = y0;
            if (x0 == x1 || y0 == y1) {
                for (x = x0; x <= x1; ++x) {
                    for (y = y0; y <= y1; ++y) {
                        ret[valid++] = matrix[x][y];
                    }
                }
            } else {
                while (y < y1) ret[valid++] = matrix[x][y++];
                while (x < x1) ret[valid++] = matrix[x++][y];
                while (y > y0) ret[valid++] = matrix[x][y--];
                while (x > x0) ret[valid++] = matrix[x--][y];
            }
            ++x0, ++y0, --x1, --y1;
        }

        return ret;
    }
};

void test(vector<vector<int>>&& matrix, const vector<int>& expect) {
    save4print(matrix);
    assert_eq_ret(expect, Solution().spiralOrder(matrix));
}

int main() {
    test({{3}, {2}}, {3, 2});
    test({{6, 9, 7}}, {6, 9, 7});
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5});
    test({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7});
    return 0;
}
