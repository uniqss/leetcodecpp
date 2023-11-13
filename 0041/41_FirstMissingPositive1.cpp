#include "../inc.h"

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int vmin = INT_MAX, nsize = nums.size(), valididx, ridx = nsize;
        int64_t sum = 0;
        for (int i = 0; i < ridx; ++i) {
            if (nums[i] <= 0) {
                swap(nums[i], nums[--ridx]);
            }
            if (nums[i] > 0) {
                sum += nums[i];
                valididx = i;
                vmin = min(vmin, nums[i]);
            }
        }
        if (vmin > 1) return 1;
        while (true) {
            int larger = 0, target = valididx + 1;
            for (int l = 0; l <= valididx; ++l) {
                if (nums[l] > target) {
                    sum -= nums[l];
                    swap(nums[l], nums[valididx--]);
                    ++larger;
                }
            }
            if (larger == 0) return target + 1;
        }
        return valididx + 1;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().firstMissingPositive(nums));
}

int main() {
    test({1, 1}, 2);
    test({1, 2, 0}, 3);
    test({3, 4, -1, 1}, 2);
    test({7, 8, 9, 11, 12}, 1);
    return 0;
}
