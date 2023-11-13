#include "../inc.h"

class Solution {
   public:
    int uniquePaths(int m, int n) {}
};

void test(int m, int n, int expect) {
    save4print(m, n);
    assert_eq_ret(expect, Solution().uniquePaths(m, n));
}

int main() {
    test(3, 7, 28);
    test(3, 2, 3);
    return 0;
}