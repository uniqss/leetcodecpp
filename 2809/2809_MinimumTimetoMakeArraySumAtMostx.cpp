#include "../inc.h"

class Solution {
   public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {}
};

void test(vector<int>&& nums1, vector<int>&& nums2, int x, int expect) {
    save4print(nums1, nums2, x);
    assert_eq_ret(expect, Solution().minimumTime(nums1, nums2, x));
}

int main() {
    test({1, 2, 3}, {1, 2, 3}, 4, 3);
    test({1, 2, 3}, {3, 3, 3}, 4, -1);
    return 0;
}
