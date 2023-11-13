#include "../inc.h"


class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {}
};

void test(vector<int>&& nums, int val, int expected) {
    save4print(nums, val);
    auto ret = Solution().removeElement(nums, val);
    assert_eq_ret(expected, ret);
}

int main() {
    test({3, 2, 2, 3}, 3, 2);
    test({0, 1, 2, 2, 3, 0, 4, 2}, 2, 5);

    return 0;
}
