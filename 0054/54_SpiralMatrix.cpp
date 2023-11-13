#include "../inc.h"

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {}
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
