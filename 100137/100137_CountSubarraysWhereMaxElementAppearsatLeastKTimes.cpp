#include "../inc.h"

class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, long long expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().countSubarrays(nums, k));
}

int main() {
    test({61, 23, 38, 23, 56, 40, 82, 56, 82, 82, 82, 70, 8, 69, 8, 7, 19, 14, 58, 42, 82, 10, 82, 78, 15, 82}, 2, 224);
    test({1, 3, 2, 3, 3}, 2, 6);
    test({1, 4, 2, 1}, 3, 0);
    return 0;
}
