#include "../inc.h"

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, int expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().longestOnes(nums, k));
}

int main() {
    test({0, 0, 1, 1, 1, 1}, 0, 4);
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 0, 4);
    test({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6);
    test({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10);
    return 0;
}
