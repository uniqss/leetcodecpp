#include "../inc.h"

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        unordered_set<size_t> zerox;
        unordered_set<size_t> zeroy;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zerox.insert(i);
                    zeroy.insert(j);
                }
            }
        }
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (zerox.count(i) > 0 || zeroy.count(j) > 0) matrix[i][j] = 0;
            }
        }
    }
};

void test(vector<vector<int>>&& matrix, const vector<vector<int>>& expect) {
    save4print(matrix);
    Solution().setZeroes(matrix);
    assert_eq_ret(expect, matrix);
}

int main() {
    test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});
    test({{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}});
    return 0;
}
