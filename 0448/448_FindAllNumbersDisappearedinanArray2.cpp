#include "../inc.h"

// interesting solution
class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int& ni : nums) {
            while (ni != nums[ni - 1]) swap(ni, nums[ni - 1]);
        }
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) ret.emplace_back(i + 1);
        }
        return ret;
    }
};

void test(vector<int>&& nums, vector<int>&& expect) {
    sort(expect.begin(), expect.end());
    auto ret = Solution().findDisappearedNumbers(nums);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({4, 3, 2, 7, 8, 2, 3, 1}, {5, 6});
    test({1, 1}, {2});
    return 0;
}
