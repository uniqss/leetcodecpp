#include "../inc.h"

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
        praw("ok.");
    } else {
        praw("not ok.");
        praw(n);
        pvvraw(expect);
        pvvraw(ret);
        pnewline();
    }
}

int main() {
    test(4, {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}});
    test(1, {{"Q"}});
    return 0;
}
