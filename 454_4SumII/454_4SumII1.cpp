#include "../inc.h"

/*
brute-force
time exceeded...
*/

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ret = 0;
        for (int i : nums1) {
            for (int j : nums2) {
                for (int k : nums3) {
                    for (int l : nums4) {
                        if (i + j + k + l == 0) ++ret;
                    }
                }
            }
        }
        return ret;
    }
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
