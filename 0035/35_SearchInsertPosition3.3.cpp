#include "../inc.h"

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int ub = upper_bound_le(nums, target);
        return ub >= 0 ? ub : nums.size();
    }
    // 找到 target <= nums[x] 的最小 x，如无，返回-1
    int upper_bound_le(const vector<int>& nums, int target) const {
        int l = 0, r = nums.size() - 1, mid;
        if (target <= nums[l]) return l;
        if (!(target <= nums[r])) return -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (target <= nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
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
