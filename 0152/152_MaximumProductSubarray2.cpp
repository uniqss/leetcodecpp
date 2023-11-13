#include "../inc.h"

class Solution {
   public:
    int max3(int i1, int i2, int i3) { return max(i1, max(i2, i3)); }
    int min3(int i1, int i2, int i3) { return min(i1, min(i2, i3)); }
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), start = 0, ret = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ret = max(ret, 0);
                ret = max(ret, helper(nums, start, i - 1));
                start = i + 1;
            }
        }
        ret = max(ret, helper(nums, start, n - 1));
        return ret;
    }
    int helper(const vector<int>& nums, int l, int r) {
        if (l > r) return INT_MIN;
        int vmin = nums[l], vmax = nums[l], ret = nums[l];
        for (int i = l + 1; i <= r; ++i) {
            int v1 = vmin * nums[i], v2 = vmax * nums[i];
            vmin = min3(v1, v2, nums[i]);
            vmax = max3(v1, v2, nums[i]);
            ret = max(ret, vmax);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int exepct) {
    auto p1 = nums;
    Solution so;
    auto ret = so.maxProduct(nums);
    assert_eq_ret(exepct, ret);
    print(p1);
}

int main() {
    test({-2, 3, -4}, 24);
    test({-3, -1, -1}, 3);
    test({0}, 0);
    test({-2}, -2);
    test({2, 3, -2, 4}, 6);
    test({-2, 0, -1}, 0);
    return 0;
}