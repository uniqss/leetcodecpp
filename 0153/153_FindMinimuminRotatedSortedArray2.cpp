#include "../inc.h"

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while (true) {
            if (nums[l] <= nums[r]) return nums[l];
            mid = l + (r - l) / 2;
            if (nums[mid] >= nums[l])
                l = mid + 1;
            else
                r = mid;
        }
        return -1;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().findMin(nums));
}

int main() {
    test({3, 4, 5, 1, 2}, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0);
    test({11, 13, 15, 17}, 11);
    return 0;
}