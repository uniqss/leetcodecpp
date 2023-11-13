#include "../inc.h"

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int l = 0, n = nums.size(), ret = INT_MIN;
        nums.emplace_back(INT_MIN);
        ++n;
        int negcount = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, nums[i]);
            if (nums[i] == 0 || nums[i] == INT_MIN) {
                ret = max(ret, helper(nums, l, i - 1, negcount));
                negcount = 0;
                l = i + 1;
            } else if (nums[i] < 0)
                ++negcount;
        }
        return ret;
    }
    int helper(const vector<int>& nums, int l, int r, int negcount) {
        if (l > r) return INT_MIN;
        int ret = 1;
        if (negcount % 2 == 0) {
            for (int i = l; i <= r; ++i) ret *= nums[i];
        } else {
            int retl = 1, retr = 1;
            int negl = l, negr = r;
            while (nums[negl] > 0) ++negl;
            while (nums[negr] > 0) --negr;
            if (negl == negr) {
                if (negl > l) {
                    for (int i = l; i < negl; ++i) retl *= nums[i];
                } else {
                    retl = INT_MIN;
                }
                if (negr < r) {
                    for (int i = negr + 1; i <= r; ++i) retr *= nums[i];
                } else {
                    retr = INT_MIN;
                }
            } else {
                int vmid = 1;
                for (int i = negl + 1; i < negr; ++i) vmid *= nums[i];
                retl = vmid;
                for (int i = l; i <= negl; ++i) retl *= nums[i];
                retr = vmid;
                for (int i = negr; i <= r; ++i) retr *= nums[i];
            }
            ret = max(retl, retr);
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