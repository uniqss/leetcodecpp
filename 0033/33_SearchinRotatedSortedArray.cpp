#include "../inc.h"

class Solution {
   public:
    int search(vector<int>& nums, int target) {}
};

void test(vector<int>&& nums, int target, int exepct) {
    save4print(nums, target);
    assert_eq_ret(exepct, Solution().search(nums, target));
}

int main() {
    test({5, 1, 3}, 3, 2);
    test({4, 5, 6, 7, 8, 1, 2, 3}, 8, 4);
    test({3, 5, 1}, 3, 0);
    test({3, 1}, 1, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0, 4);
    test({4, 5, 6, 7, 0, 1, 2}, 3, -1);
    test({1}, 0, -1);
    test({1}, 1, 0);
    return 0;
}