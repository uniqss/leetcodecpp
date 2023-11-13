#include "../inc.h"

/*
可读性好太多，性能差太多。。。
*/
class Solution {
   public:
    int search(vector<int>& nums, int target) { return helper(nums, target, 0, nums.size() - 1); }
    int helper(const vector<int>& nums, int target, int l, int r) {
        if (l == r) return nums[l] == target ? l : -1;
        if (l > r) return -1;
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && nums[mid] > target) {
                return helper(nums, target, l, mid - 1);
            } else {
                return helper(nums, target, mid + 1, r);
            }
        } else {
            if (nums[mid] < target && target <= nums[r]) {
                return helper(nums, target, mid + 1, r);
            } else {
                return helper(nums, target, l, mid - 1);
            }
        }
    }
};

void test(vector<int>&& nums, int target, int exepct) {
    save4print(nums, target);
    assert_eq_ret(exepct, Solution().search(nums, target));
}

int main() {
    test({3, 1}, 1, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0, 4);
    test({4, 5, 6, 7, 0, 1, 2}, 3, -1);
    test({1}, 0, -1);
    return 0;
}