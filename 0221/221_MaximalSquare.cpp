#include "../inc.h"

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {}
};

void test(vector<vector<string>>&& matrix, int expect) {
    save4print(matrix);
    auto m = vvs2vvc(matrix);
    assert_eq_ret(expect, Solution().maximalSquare(m));
}

int main() {
    test({{"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}},
         4);
    test({{"0", "1"}, {"1", "0"}}, 1);
    test({{"0"}}, 0);
    return 0;
}
