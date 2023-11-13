#include "../inc.h"

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {}
};

void test(vector<int>&& vi, int expect) {
    save4print(vi);
    assert_eq_ret(expect, Solution().largestRectangleArea(vi));
}

int main() {
    test({4, 2, 0, 3, 2, 5}, 6);
    test({2, 0, 2}, 2);
    test({2, 1, 5, 6, 2, 3}, 10);
    test({2, 4}, 4);
    test({2, 1, 2}, 3);
    test({5}, 5);
    return 0;
}
