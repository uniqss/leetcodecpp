#include "../inc.h"

class Solution {
   public:
    int rob(vector<int>& nums) {
        int vrob = nums[0], vnrob = 0, ret = vrob, n = nums.size();
        for (int i = 1; i < n; ++i) {
            int vrobpre = vrob, vnrobpre = vnrob;
            vrob = vnrobpre + nums[i];
            vnrob = max(vnrobpre, vrobpre);
            ret = max(vrob, vnrob);
        }
        return ret;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().rob(nums));
}

int main() {
    test({0}, 0);
    test({1, 2, 3, 1}, 4);
    test({2, 7, 9, 3, 1}, 12);
    test({2, 1, 1, 2}, 4);
    return 0;
}
