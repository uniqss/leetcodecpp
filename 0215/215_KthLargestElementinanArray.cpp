#include "../inc.h"

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, int expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().findKthLargest(nums, k));
}

int main() {
    test({7, 6, 5, 4, 3, 2, 1}, 2, 6);
    test({3, 2, 1, 5, 6, 4}, 2, 5);
    test({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4);
    return 0;
}
