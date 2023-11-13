#include "../inc.h"

// 这似乎才是正统解
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = std::upper_bound(nums.begin(), nums.end(), target, std::less_equal<int>());
        if (it == nums.end()) return nums.size();
        return it - nums.begin();
    }
};

void test(vector<int>&& nums, int target, int expect) {
    save4print(nums, target);
    assert_eq_ret(expect, Solution().searchInsert(nums, target));
}

int main() {
    test({1}, 1, 0);
    test({1, 3, 5, 6}, 1, 0);
    test({1, 3, 5, 6}, 5, 2);
    test({1, 3, 5, 6}, 2, 1);
    test({1, 3, 5, 6}, 7, 4);
    test({1, 3, 5, 6}, 0, 0);

    return 0;
}
