#include "../inc.h"

/*
这个解法的关键在于非常好的利用了【左边和右边元素数量相等】这一特征
*/
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        // m个元素， m+1个空位, [0, m]种切法
        int left = 0, right = m;
        // max left, min right
        int median1 = 0, median2 = 0;
        while (left <= right) {
            // left: nums1[0 .. i - 1]   nums2[0 .. j - 1]
            int i = (left + right) / 2;
            /* i切，nums1左[0 .. i - 1]总共i个，右[i .. m - 1],m - i个
             假设j切nums2左[0 .. j - 1]总共j个，右[j .. n - 1],n - j个
             m+n奇：i + j = (m + n + 1) / 2 (左边要多一个)
             m+n偶：i + j = (m + n) / 2 = (m + n + 1) / 2
             所以 j = (m + n + 1) / 2 - i
            */
            // right: nums1[i .. m - 1]  nums2[j .. n - 1]
            int j = (m + n + 1) / 2 - i;
            int nums_im1 = i == 0 ? INT_MIN : nums1[i - 1];
            int nums_i = i == m ? INT_MAX : nums1[i];
            int nums_jm1 = j == 0 ? INT_MIN : nums2[j - 1];
            int nums_j = j == n ? INT_MAX : nums2[j];
            if (nums_im1 <= nums_j) {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
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