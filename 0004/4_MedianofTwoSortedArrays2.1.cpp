#include "../inc.h"

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size(), lmax = 0, rmin = 0;
        int l = 0, r = m;
        while (l <= r) {
            /*
            0..i..m
            0..x..n
            偶：
            i + x = m - i + n - x
            x * 2 = m + n - i * 2
            x = (m + n) / 2 - i
            奇，左多1：
            i + x = m - i + n - x + 1
            x = (m + n + 1) / 2 - i
            所以，简单起见
            x = (m + n + 1) / 2 - i
            */
            int i = l + (r - l) / 2;
            int j = (m + n + 1) / 2 - i;
            int vipre = i == 0 ? INT_MIN : nums1[i - 1];
            int vi = i == m ? INT_MAX : nums1[i];
            int vjpre = j == 0 ? INT_MIN : nums2[j - 1];
            int vj = j == n ? INT_MAX : nums2[j];
            if (vipre <= vj) {
                l = i + 1;
                lmax = max(vipre, vjpre);
                rmin = min(vi, vj);
            } else {
                r = i - 1;
            }
        }
        return ((m + n) % 2 == 1) ? lmax : (lmax + rmin) / 2.0;
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