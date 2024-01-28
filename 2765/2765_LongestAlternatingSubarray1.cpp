#include "../inc.h"

class Solution {
   public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), imax = 0, dmax = 0;
        vector<int> inc(n), dec(n);
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                inc[i] = dec[i - 1] + 1;
                imax = max(imax, inc[i]);
            }
            if (nums[i] == nums[i - 1] - 1) {
                dec[i] = inc[i - 1] + 1;
                dmax = max(dmax, dec[i]);
            }
        }
        if (imax == 0 && dmax <= 1) return -1;
        int ret = max((imax & 1) ? imax + 1 : imax, (dmax & 1) ? dmax : dmax + 1);
        return ret > 0 ? ret : -1;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().alternatingSubarray(nums));
}
int main() {
    test({2, 3, 4, 3, 4}, 4);
    test({4, 5, 6}, 2);
    return 0;
}