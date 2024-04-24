#include "../inc.h"

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {}
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
