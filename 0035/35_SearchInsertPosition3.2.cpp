#include "../inc.h"

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int ret = upper_bound(nums, target);
        return ret >= 0 ? ret : nums.size();
    }
    // stl std::upper_bound 的写法
    int upper_bound(const vector<int>& nums, int target) {
        int l = 0, r = nums.size(), len = r - l;
        // [)
        while (len > 0) {
            int half = len >> 1;
            int mid = l + half;
            if (target <= nums[mid])
                len = half;
            else {
                l = mid + 1;
                len = len - half - 1;
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
