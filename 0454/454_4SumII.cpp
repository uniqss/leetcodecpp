#include "../inc/inc.h"

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {}
};

void test(vector<int>&& nums1, vector<int>&& nums2, vector<int>&& nums3, vector<int>&& nums4, int expect) {
    Solution so;
    auto ret = so.fourSumCount(nums1, nums2, nums3, nums4);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(nums1);
        print(nums2);
        print(nums3);
        print(nums4);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2}, {-2, -1}, {-1, 2}, {0, 2}, 2);
    test({0}, {0}, {0}, {0}, 1);
    return 0;
}
