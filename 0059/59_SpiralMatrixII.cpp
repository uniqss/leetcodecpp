#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {}
};

void test(int n, vector<vector<int>>&& expect) {
    Solution so;
    auto ret = so.generateMatrix(n);
    if (ret == expect) {
        print("ok");
    } else {
        print("not ok.");
        print(n);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(4, {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}});
    test(3, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}});
    test(1, {{1}});
    return 0;
}
