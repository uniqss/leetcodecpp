#include "../inc.h"

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nsize = nums.size(), plusr = 1;
        vector<int> ret(nsize, 1);
        for (int i = 1; i < nsize; ++i) {
            ret[i] = ret[i - 1] * nums[i - 1];
        }
        for (int i = nsize - 2; i >= 0; --i) {
            plusr *= nums[i + 1];
            ret[i] *= plusr;
        }

        return ret;
    }
};

void test(vector<int>&& nums, const vector<int>& expect) {
    auto nums_param = nums;
    Solution so;
    auto ret = so.productExceptSelf(nums);
    assert_eq_ret(expect, ret);
    print(nums_param);
}

int main() {
    test({1, 2, 3, 4}, {24, 12, 8, 6});
    test({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});
    return 0;
}
