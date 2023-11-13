#include "../inc.h"

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {}
};

void test(vector<vector<int>>&& matrix, int target, bool expect) {
    save4print(matrix, target);
    assert_eq_ret(expect, Solution().searchMatrix(matrix, target));
}

int main() {
    test({{1, 1}}, 2, false);
    test({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3, true);
    test({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13, false);
    return 0;
}
