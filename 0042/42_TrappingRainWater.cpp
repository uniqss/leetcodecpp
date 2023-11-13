#include "../inc.h"

class Solution {
   public:
    int trap(vector<int>& height) {}
};

void test(vector<int>&& vi, int expect) {
    save4print(vi);
    assert_eq_ret(expect, Solution().trap(vi));
}

int main() {
    test({2, 1, 3, 1}, 1);
    test({2, 1, 0, 1, 3, 1}, 4);
    test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6);
    test({4, 2, 0, 3, 2, 5}, 9);
    return 0;
}
