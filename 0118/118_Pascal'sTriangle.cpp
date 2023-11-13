#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {}
};

void test(int numRows, const vector<vector<int>>& expect) {
    save4print(numRows);
    assert_eq_ret(expect, Solution().generate(numRows));
}

int main() {
    test(5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}});
    test(1, {{1}});
    return 0;
}
