#include "../inc.h"

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int ret = 0;
        int nsize = nums.size();
        int l = 0, r = nsize, mid = 0;
        if (target < nums[0]) return 0;
        if (target > nums[nsize - 1]) return nsize;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (mid > 0 && mid < nsize && nums[mid - 1] < target && nums[mid] > target) return mid;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return mid;
    }
};

void test(vector<int>&& nums, int target, int expect) {
    save4print(nums, target);
    assert_eq_ret(expect, Solution().searchInsert(nums, target));
}

int main() {
    test({1, 3, 5, 6}, 5, 2);
    test({1, 3, 5, 6}, 2, 1);
    test({1, 3, 5, 6}, 7, 4);
    test({1, 3, 5, 6}, 0, 0);

    return 0;
}
