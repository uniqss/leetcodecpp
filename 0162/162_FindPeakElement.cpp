#include "../inc.h"

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {}
};

void test(vector<int>&& nums) {
    save4print(nums);
    auto ret = Solution().findPeakElement(nums);
    if (ret == -1) {
        assert_retnone(ret != -1);
    }
    int64_t vret = nums[ret];
    int64_t vl = ret > 0 ? nums[ret - 1] : (int64_t)INT_MIN - 1;
    int64_t vr = ret < nums.size() - 1 ? nums[ret + 1] : (int64_t)INT_MIN - 1;
    assert_eq_ret(vret > vl && vret > vr, true);
}

int main() {
    test({3, 4, 3, 2, 1});
    test({6, 5, 4, 3, 2, 3, 2});
    test({1});
    test({1, 2});
    test({2, 1});
    test({1, 3, 2});
    test({1, 2, 3, 1});
    test({1, 2, 1, 3, 5, 6, 4});
    return 0;
}
