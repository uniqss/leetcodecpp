#include "../inc.h"

/*
强制把upper_bound和lower_bound记到脑海中，作为随时可写可用的基石，二分基本就秒杀
*/
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int u = upper_bound(nums, target);
        if (u == -1) return nums.size();
        return u;
    }
    // first >= target
    int upper_bound(const vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1, mid;
        if (nums[l] >= target) return l;
        if (nums[r] < target) return -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
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
    test({1, 3, 5, 6}, 5, 2);
    test({1, 3, 5, 6}, 2, 1);
    test({1, 3, 5, 6}, 7, 4);
    test({1, 3, 5, 6}, 0, 0);

    return 0;
}
