#include "../inc.h"

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {}
};

void test(vector<int>&& nums1, vector<int>&& nums2, double expect) {
    save4print(nums1, nums2);
    assert_eq_ret(expect, Solution().findMedianSortedArrays(nums1, nums2));
}

int main() {
    test({2}, {1, 3, 4}, 2.5);
    test({1, 3}, {2}, 2.0);
    test({1, 3}, {2, 4}, 2.5);
    test({1, 2, 3, 4}, {5, 6}, 3.5);
    test({1, 2, 3, 4}, {5, 6, 7}, 4);
    test({1, 2, 3, 4}, {5, 6, 7, 8}, 4.5);
    test({1, 2}, {3, 4}, 2.5);
    return 0;
}