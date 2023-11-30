#include "../inc.h"

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        // upper_bound的意义(from cppreference)：
        // tepmlate< class ForwardIt, class T, class Compare >
        // constexpr ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp)
        // Returns an iterator pointing to the first element in the range [first, last) such that
        // value < element (or comp(value, element)) is true (i.e. that is strictly greater than value), or last if no
        // such element is found.
        auto ub = upper_bound(nums.begin(), nums.end(), target - 1);
        return ub - nums.begin();
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
