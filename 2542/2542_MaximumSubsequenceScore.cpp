#include "../inc.h"

class Solution {
   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {}
};

void test(vector<int>&& nums1, vector<int>&& nums2, int k, long long expect) {
    save4print(nums1, nums2, k);
    assert_eq_ret(expect, Solution().maxScore(nums1, nums2, k));
}

int main() {
    test({2, 1, 14, 12}, {11, 7, 13, 6}, 3, 168);
    test({79, 76, 41, 28, 41, 66, 44, 30, 25}, {25, 0, 69, 67, 55, 0, 9, 77, 26}, 7, 2592);
    test({1, 3, 3, 2}, {2, 1, 3, 4}, 3, 12);
    test({4, 2, 3, 1, 1}, {7, 5, 10, 9, 6}, 1, 30);
    return 0;
}
