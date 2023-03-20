#include "../inc/inc.h"

class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {}
};

void test(int n, vector<vector<string>>&& expect) {
    Solution so;
    auto ret = so.solveNQueens(n);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    if (expect == ret) {
        print("ok.");
    } else {
        print("not ok.");
        print(n);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test(4, {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}});
    test(1, {{"Q"}});
    return 0;
}
