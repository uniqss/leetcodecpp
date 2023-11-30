#include "../inc.h"

class Solution {
   public:
    int rob(vector<int>& nums) {
        int nsize = nums.size();
        vector<int> dict(nsize);
        auto geti = [&](int i) { return i >= 0 ? dict[i] : 0; };
        for (int i = 0; i < nsize; ++i) {
            dict[i] = max(geti(i - 2) + nums[i], geti(i - 3) + nums[i]);
        }
        return nsize > 1 ? max(dict[nsize - 1], dict[nsize - 2]) : dict[nsize - 1];
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
