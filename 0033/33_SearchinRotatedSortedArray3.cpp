#include "../inc.h"

/*
      o .
      .
    . o
  .   o 
.     o
      o     .
      o   .


  .   o
.     o
      o     .
      o   .
      o .
      .
    . o

注意左右递增区间的边缘值的包含
*/
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    // 这里一定要逆反推理，上面取反必须也能完全满足，一定要画图看那两段线段
                    // if (nums[l] > target || target >= nums[mid])
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
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
    test({5, 1, 3}, 3, 2);
    test({4, 5, 6, 7, 8, 1, 2, 3}, 8, 4);
    test({3, 5, 1}, 3, 0);
    test({3, 1}, 1, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0, 4);
    test({4, 5, 6, 7, 0, 1, 2}, 3, -1);
    test({1}, 0, -1);
    test({1}, 1, 0);
    return 0;
}