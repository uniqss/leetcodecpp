#include "../inc.h"

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        const int offset = 3 * 10000;
        vector<int> dict(6 * 10000 + 1, 0);
        for (size_t i = 0; i < nums.size(); i++) {
            ++dict[nums[i] + offset];
        }
        for (size_t i = 0; i < dict.size(); i++) {
            if (dict[i] == 1) return i - offset;
        }
        return 0;
    }
};

void test(vector<int>&& nums, int expect) {
    save4print(nums);
    assert_eq_ret(expect, Solution().singleNumber(nums));
}

int main() {
    test({2, 2, 1}, 1);
    test({4, 1, 2, 1, 2}, 4);
    test({1}, 1);
    return 0;
}
