#include "../inc.h"

/*
此法等于是作弊了，因为范围在-30 30
之间，所以用了此法，思路是计算所有的数量，然后利用std::pow来快速计算，速度上肯定会慢于官方的 空间折叠法
*/

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto nsize = nums.size();
        vector<int> ret(nsize, 1);
        vector<int> counts(61, 0);
        for (int n : nums) {
            ++counts[n + 30];
        }
        int p = 0;
        for (int i = 0; i < nsize; ++i) {
            for (int j = 0; j < counts.size(); ++j) {
                p = counts[j];
                if (nums[i] == j - 30) --p;
                if (p > 0) ret[i] *= std::pow(j - 30, p);
            }
        }

        return ret;
    }
};

void test(vector<int>&& nums, const vector<int>& expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().productExceptSelf(nums));
}

int main() {
    test({1, 2, 3, 4}, {24, 12, 8, 6});
    test({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});
    return 0;
}
