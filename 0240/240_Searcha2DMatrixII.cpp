#include "../inc.h"

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {}
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
