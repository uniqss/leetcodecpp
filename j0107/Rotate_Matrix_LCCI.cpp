#include "../inc.h"

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {}
};

void test(vector<vector<int>>&& matrix, const vector<vector<int>>& expect) {
    Solution so;
    auto param = matrix;
    so.rotate(matrix);
    if (matrix == expect) {
        print("ok");
    } else {
        print("not ok");
        print(param);
        print(expect);
        print(matrix);
        print();
    }
}

int main() {
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});

    return 0;
}
