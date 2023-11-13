#include "../inc.h"

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int nsize = nums.size();
        int l = 0, r = nsize - 1, mid = 0;
        // 记住这套二分模板  l <= r     l = mid + 1     r = mid - 1   出来 l > r 如果要大就 l 要小就 r
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // 出来 l > r 且未找到，这个时候应该取大的，也就是 l
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
