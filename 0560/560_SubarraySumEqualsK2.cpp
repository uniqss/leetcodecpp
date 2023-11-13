#include "../inc.h"

/*
未学得前缀合之精髓也
*/
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum2count;
        sum2count[0] = 1;
        int sum = 0, ret = 0;
        for (int n : nums) {
            sum += n;
            if (sum2count.count(sum - k) > 0) {
                ret += sum2count[sum - k];
            }
            ++sum2count[sum];
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
