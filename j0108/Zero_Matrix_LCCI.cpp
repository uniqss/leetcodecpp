#include "../inc.h"

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {}
};

void test(vector<vector<int>>&& matrix, const vector<vector<int>>& expect) {
    Solution so;
    auto param = matrix;
    so.setZeroes(matrix);
    if (matrix == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(param);
        print(expect);
        print(matrix);
        print();
    }
}

int main() {
    test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});
    test({{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}});
    return 0;
}
