#include "../inc.h"

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            return findKth(nums1, nums2, total / 2 + 1);
        } else {
            return (findKth(nums1, nums2, total / 2) + findKth(nums1, nums2, total / 2 + 1)) / 2.0;
        }
    }
    double findKth(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size(), index1 = 0, index2 = 0;
        while (true) {
            if (index1 == m) return nums2[index2 + k - 1];
            if (index2 == n) return nums1[index1 + k - 1];
            if (k == 1) return min(nums1[index1], nums2[index2]);
            int newindex1 = min(index1 + k / 2 - 1, m - 1);
            int newindex2 = min(index2 + k / 2 - 1, n - 1);
            if (nums1[newindex1] <= nums2[newindex2]) {
                k -= newindex1 - index1 + 1;
                index1 = newindex1 + 1;
            } else {
                k -= newindex2 - index2 + 1;
                index2 = newindex2 + 1;
            }
        }
    }
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