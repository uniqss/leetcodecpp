#include "../inc.h"

class Solution {
   public:
    int totalNQueens(int n) {}
};

void test(int n, int expect) {
    save4print(n);
    assert_eq_ret(expect, Solution().totalNQueens(n));
}

int main() {
    test(4, 2);
    return 0;
}
