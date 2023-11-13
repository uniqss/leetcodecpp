#include "../inc.h"

class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {}
};

void test(int n, vector<vector<string>>&& expect) {
    save4print(n);
    auto ret = Solution().solveNQueens(n);
    std::sort(expect.begin(), expect.end());
    std::sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test(4, {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}});
    test(1, {{"Q"}});
    return 0;
}
