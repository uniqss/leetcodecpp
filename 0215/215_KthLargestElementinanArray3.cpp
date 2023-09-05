#include "../inc.h"

class Solution {
   public:
    int helper(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[k];
        int i = l - 1, j = r + 1, partion = nums[l];
        while (i < j) {
            do ++i; while (nums[i] < partion);
            do --j; while (nums[j] > partion);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (j >= k) return helper(nums, l, j, k);
        else return helper(nums, j + 1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return helper(nums, 0, n - 1, n - k);
    }
};

void test(vector<int>&& nums, int k, int expect) {
    auto n_param = nums;
    Solution so;
    auto ret = so.findKthLargest(nums, k);
    assert_eq_ret(expect, ret);
    print(n_param);
    print(k);
}

int main() {
    test({7, 6, 5, 4, 3, 2, 1}, 2, 6);
    test({3, 2, 1, 5, 6, 4}, 2, 5);
    test({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4);
    return 0;
}
