#include "../inc.h"

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {}
};

void test(vector<vector<int>>&& triangle, int expect) {
    save4print(triangle);
    assert_eq_ret(expect, Solution().minimumTotal(triangle));
}

int main() {
    test({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11);
    test({{-10}}, -10);
    return 0;
}
