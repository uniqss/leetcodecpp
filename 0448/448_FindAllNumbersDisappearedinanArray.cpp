#include "../inc.h"

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {}
};

void test(vector<int>&& nums, vector<int>&& expect) {
    sort(expect.begin(), expect.end());
    auto ret = Solution().findDisappearedNumbers(nums);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({4, 3, 2, 7, 8, 2, 3, 1}, {5, 6});
    test({1, 1}, {2});
    return 0;
}
