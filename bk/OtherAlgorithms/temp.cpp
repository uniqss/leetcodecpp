#include "../inc.h"

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        if (size == 0) return 0;
        int index = size / 2;
        int i = 0, j = 0;
        vector<int> temp;
        int temp_size = 0;
        while (temp_size < index + 1) {
            if (i < size1 && (j >= size2 || nums1[i] <= nums2[j])) {
                temp.push_back(nums1[i]);
                i++;
            } else if (j < size2 && (i >= size1 || nums1[i] > nums2[j])) {
                temp.push_back(nums2[j]);
                j++;
            }
            temp_size = temp.size();
        }
        if (size % 2 == 1) {
            // cout << temp[index];  //这里注释或者去掉会出错，真的有毛病
            return temp[index];
        } else {
            return (temp[index] + temp[index - 1]) / 2.0;
        }
    }
};

void test(vector<int>&& nums1, vector<int>&& nums2, double expect) {
    Solution so;
    auto ret = so.findMedianSortedArrays(nums1, nums2);
    if (expect == ret) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums1);
        print(nums2);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 3}, {2}, 2.0);
    return 0;
}
