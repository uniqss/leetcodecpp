#include "../inc.h"

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target, less<int>());
        if (lb == nums.end() || *lb != target) return {-1, -1};
        auto ub = upper_bound(nums.begin(), nums.end(), target, less<int>());
        return {(int)(lb - nums.begin()), (int)(ub - nums.begin() - 1)};
    }
};

void test(vector<int>&& nums, int target, const vector<int>& expect) {
    save4print(nums, target);
    assert_eq_ret(expect, Solution().searchRange(nums, target));
}

int main() {
    test({5, 7, 7, 8, 8, 10}, 8, {3, 4});
    test({5, 7, 7, 8, 8, 10}, 6, {-1, -1});
    test({1}, 0, {-1, -1});
    test({1}, 1, {0, 0});
    test({1}, 2, {-1, -1});
    test({}, 0, {-1, -1});
    return 0;
}