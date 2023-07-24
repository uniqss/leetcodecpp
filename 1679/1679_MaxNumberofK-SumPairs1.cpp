#include "../inc.h"

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        int l = 0, nsize = nums.size(), r = nsize - 1, sum = 0;
        while (l < r) {
            sum = nums[l] + nums[r];
            if (sum == k) {
                ++ret;
                ++l, --r;
            } else if (sum < k) {
                ++l;
            } else {
                --r;
            }
        }

        return ret;
    }
};

void test(vector<int>&& nums, int k, int expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.maxOperations(nums, k);
    assert_eq_ret(expect, ret);
    print(nums_param);
    print(k);
}

int main() {
    test({1, 2, 3, 4}, 5, 2);
    test({3, 1, 3, 4, 3}, 6, 1);
    return 0;
}
