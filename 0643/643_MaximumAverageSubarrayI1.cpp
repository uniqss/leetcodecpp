#include "../inc.h"

class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ret = 0.0, avg = 0.0;
        int nsize = nums.size();
        for (int i = 0; i < k; ++i) {
            avg += (double)nums[i] / k;
        }
        ret = avg;
        for (int i = k; i < nsize; ++i) {
            avg += (double)(nums[i] - nums[i - k]) / k;
            ret = max(ret, avg);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int k, double expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().findMaxAverage(nums, k));
}

int main() {
    test({-1}, 1, -1);
    test({1, 12, -5, -6, 50, 3}, 4, 12.75000);
    test({5}, 1, 5.00000);
    return 0;
}
