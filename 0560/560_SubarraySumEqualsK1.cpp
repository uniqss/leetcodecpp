#include "../inc.h"

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum2count;
        int ret = 0;
        for (int n : nums) {
            unordered_map<int, int> curr;
            curr[n] = 1;
            for (const auto& [sum, count] : sum2count) {
                curr[sum + n] += count;
            }
            ret += curr[k];
            sum2count = curr;
        }
        return ret;
    }
};

void test(vector<int>&& nums, int k, int expect) {
    auto p1 = nums;
    Solution so;
    auto ret = so.subarraySum(nums, k);
    assert_eq_ret(expect, ret);
    print(p1);
    print(k);
}

int main() {
    test({1, 1, 1}, 2, 2);
    test({1, 2, 3}, 3, 2);
    return 0;
}
