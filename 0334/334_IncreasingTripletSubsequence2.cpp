#include "../inc.h"

/*
这个思路其实更容易理解，从左到右整个最小的数组，从右到左整个最大的数组。然后从第2个到倒数第2个，找出某一个比min[i]大比max[i]小的，找不到false
*/

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int nsize = nums.size();
        if (nsize < 3) return false;
        vector<int> lmin(nsize, nums[0]);
        vector<int> rmax(nsize, nums[nsize - 1]);
        for (int i = 1; i < nsize; ++i) {
            lmin[i] = std::min(nums[i], lmin[i - 1]);
        }
        for (int i = nsize - 2; i >= 0; --i) {
            rmax[i] = std::max(nums[i], rmax[i + 1]);
        }
        for (int i = 1; i < nsize - 1; ++i) {
            if (nums[i] > lmin[i] && nums[i] < rmax[i]) return true;
        }

        return false;
    }
};

void test(vector<int>&& nums, bool expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.increasingTriplet(nums);
    assert_eq_ret(expect, ret);
    print(nums_param);
}

int main() {
    test({20, 100, 10, 12, 5, 13}, true);
    test({2, 4, -2, -3}, false);
    test({1, 2, 3, 4, 5}, true);
    test({5, 4, 3, 2, 1}, false);
    test({2, 1, 5, 0, 4, 6}, true);
    return 0;
}
