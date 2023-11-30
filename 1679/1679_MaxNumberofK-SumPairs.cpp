#include "../inc.h"

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, int expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().maxOperations(nums, k));
}

int main() {
    test({1, 2, 3, 4}, 5, 2);
    test({3, 1, 3, 4, 3}, 6, 1);
    return 0;
}
