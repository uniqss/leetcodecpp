#include "../inc.h"

/*
写是写出来了，不过写的像坨屎
*/
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        /*
        首先一定折半,valmid
        无论怎么切，都会形成一个单调区间，判定target是否落在单调区间，在则区间找，不在则非区间找
        */
        int l = 0, r = nums.size() - 1;
        // []
        while (l <= r) {
            int mid = (l + r) / 2, valmid = nums[mid];
            if (nums[mid] == target) return mid;
            if (mid == l) {
                ++l;
                continue;
            }
            if (nums[l] < nums[r]) {
                if (valmid < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (valmid > nums[l]) {
                    if (valmid > target && nums[l] <= target) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                } else {
                    if (valmid < target && nums[r] >= target) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }
        }
        return -1;
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